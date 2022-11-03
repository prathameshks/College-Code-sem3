#include <iostream>
#include <math.h>
#include <graphics.h>
#include <string>
using namespace std;

// basic point with x and y
class Point
{
public:
    int x, y;
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    Point()
    {
        x = 0;
        y = 0;
    }
};

// DDA Line algorithm to draw line
void drawline(Point p1, Point p2, _color col = RED, int Delay = 1)
{
    // Calculate dx and dy
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int step;

    // If dx > dy we will take step as dx
    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    // Calculate x-increment and y-increment for each step
    float x_incr = (float)dx / step;
    float y_incr = (float)dy / step;

    // Take the initial points as x and y
    float x = p1.x;
    float y = p1.y;

    for (int i = 0; i < step; i++)
    {
        delay(Delay);

        putpixel(round(x), round(y), col);
        x += x_incr;
        y += y_incr;
        // delay(10);
    }
}

// window with 4 points from top left clockwise 1 to 4
class Window
{
public:
    Point p1, p2, p3, p4;

    Window(Point p1, Point p2, Point p3, Point p4)
    {
        // clockwise from top left
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
    }
    Window()
    {
    }
    Window(Point p1, Point p3)
    {
        this->p1 = p1;
        this->p3 = p3;
        this->p2.x = p3.x;
        this->p2.y = p1.y;
        this->p4.x = p1.x;
        this->p4.y = p3.y;
    }
    void draw(_color col = RED, int Delay = 1)
    {
        drawline(p1, p2, col, Delay);
        drawline(p2, p3, col, Delay);
        drawline(p3, p4, col, Delay);
        drawline(p4, p1, col, Delay);
    }

    void Display_coords()
    {
        cout << p1.x << " " << p1.y << endl;
        cout << p2.x << " " << p2.y << endl;
        cout << p3.x << " " << p3.y << endl;
        cout << p4.x << " " << p4.y << endl;
    }
};

string setpntcode(Point p1, Window w)
{
    // top bottom right left
    string tmpcode = "0000";

    // for p1
    if (p1.x < w.p1.x)
        tmpcode[3] = '1';
    if (p1.x > w.p2.x)
        tmpcode[2] = '1';
    if (p1.y < w.p1.y)
        tmpcode[0] = '1';
    if (p1.y > w.p4.y)
        tmpcode[1] = '1';

    return tmpcode;
}

// line class with point p1 and p2
class Line
{
public:
    string code1 = "", code2 = "";
    Point p1, p2;

    Line(Point p1, Point p2)
    {
        this->p1 = p1;
        this->p2 = p2;
    }
    Line(int x1, int x2, int y1, int y2)
    {
        p1 = Point(x1, y1);
        p2 = Point(x2, y2);
    }
    void displaycode()
    {
        cout << code1 << " & " << code2 << endl;
    }

    void draw(_color col = RED, int Delay = 1)
    {
        drawline(p1, p2, col, Delay);
    }

    void setcode(Window w)
    {
        // top bottom right left
        code1 = setpntcode(p1, w);
        code2 = setpntcode(p2, w);
    }
};

// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
bool cohenSutherlandClip(Line *l, Window w, Line *res)
{
    // Compute region codes for P1, P2
    l->setcode(w);
    int code1 = stoi(l->code1, 0, 2);
    int code2 = stoi(l->code2, 0, 2);
    double x1 = l->p1.x;
    double y1 = l->p1.y;
    double x2 = l->p2.x;
    double y2 = l->p2.y;
    // Defining region codes
    const int INSIDE = 0; // 0000
    const int LEFT = 1;   // 0001
    const int RIGHT = 2;  // 0010
    const int BOTTOM = 4; // 0100
    const int TOP = 8;    // 1000

    // Initialize line as outside the rectangular window
    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle, in same region
            break;
        }
        else
        {
            // Some segment of line lies within the rectangle
            int code_out;
            double x, y;

            // At least one endpoint is outside the
            // rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (w.p3.y - y1) / (y2 - y1);
                y = w.p3.y;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (w.p1.y - y1) / (y2 - y1);
                y = w.p1.y;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (w.p3.x - x1) / (x2 - x1);
                x = w.p3.x;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (w.p1.x - x1) / (x2 - x1);
                x = w.p1.x;
            }

            // Now intersection point x, y is found
            // We replace point outside rectangle
            // by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                Point p1(x1, y1);

                code1 = stoi(setpntcode(p1, w), 0, 2);
            }
            else
            {
                x2 = x;
                y2 = y;
                Point p1(x2, y2);

                code2 = stoi(setpntcode(p1, w), 0, 2);
            }
        }
    }
    if (accept)
    {
        // set new line points
        l->p1.x = x1;
        l->p1.y = y1;
        l->p2.y = y2;
        l->p2.x = x2;
        return true;
    }
    else
    {
        // cout << "Line rejected" << endl;
        return false;
    }
}

// Driver code
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // initialize graph
    Line linearr[10];

    Point p1(100, 100), p2(300, 100), p3(300, 200), p4(100, 200);
    Window w1(p1, p2, p3, p4);
    w1.draw();

    linearr[0] = Line(110, 150, 110, 190);
    linearr[1] = Line(150, 160, 90, 80);
    linearr[2] = Line(100, 220, 90, 80);

    for (int i = 0; i < 3; i++)
    {

        cohenSutherlandClip(&linearr[0], w1);
    }
`   
    getch();
    closegraph();
    return 0;
}