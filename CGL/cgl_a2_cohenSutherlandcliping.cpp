#include <iostream>
#include <math.h>
#include <graphics.h>
#include <string>
using namespace std;

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// basic point with x and y
class Point
{
public:
    int x, y;
    Point(int a = 0, int b = 0)
    {
        x = a;
        y = b;
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
    Point p1, p3;

    Window()
    {
    }
    Window(Point p1, Point p3)
    {
        this->p1 = p1;
        this->p3 = p3;
    }
    void draw(_color col = RED, int Delay = 1)
    {
        drawline(p1, Point(p3.x, p1.y), col, Delay);
        drawline(Point(p3.x, p1.y), p3, col, Delay);
        drawline(p3, Point(p1.x, p3.y), col, Delay);
        drawline(Point(p1.x, p3.y), p1, col, Delay);
    }
};

int setPointCode(Point p1, Window w)
{
    // top bottom right left
    int tmpcode = 0;

    // for p1
    if (p1.x < w.p1.x)
        tmpcode |= LEFT;
    else if (p1.x > w.p3.x)
        tmpcode |= RIGHT;
    if (p1.y < w.p1.y)
        tmpcode |= TOP;
    else if (p1.y > w.p3.y)
        tmpcode |= BOTTOM;
    return tmpcode;
}

bool stringAND(string s1, string s2, int len = 4)
{
    for (int i = 0; i < len; i++)
    {
        if ((s1[i] == '1') and (s2[i] == '1'))
        {
            return true;
        }
    }
    return false;
}

// line class with point p1 and p2
class Line
{
public:
    // int code1 = -1, code2 = -1;
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
    Line()
    {
    }

    void draw(_color col = RED, int Delay = 1)
    {
        drawline(p1, p2, col, Delay);
    }

    void setcode(Window w)
    {
        // top bottom right left
        // code1 = setPointCode(p1, w);
        // code2 = SetPointCode(p2, w);
    }
};

int x_max;
int y_max;
int x_min;
int y_min;

int generateCode(double x, double y)
{
    int code = INSIDE; // intially initializing as being inside
    if (x < x_min)     // lies to the left of rectangle
        code |= LEFT;
    else if (x > x_max) // lies to the right of rectangle
        code |= RIGHT;
    if (y < y_min) // lies below the rectangle
        code |= BOTTOM;
    else if (y > y_max) // lies above the rectangle
        code |= TOP;
    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2)
{
    int code1 = generateCode(x1, y1); // Compute region codes for P1.
    int code2 = generateCode(x2, y2); // Compute region codes for P2.
    bool accept = false;              // Initialize line as outside the rectangular window.
    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle.
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle,in same region.
            break;
        }
        else
        {
            // Some segment of line lies within the rectangle.
            int code_out;
            double x, y;
            // At least one endpoint lies outside the rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
            /*
             * Find intersection point by using formulae :
             y = y1 + slope * (x - x1)
             x = x1 + (1 / slope) * (y - y1)
             */
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }
            // Intersection point x,y is found.
            // Replace point outside rectangle by intersection point.
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = generateCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = generateCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        std::cout << "Line accepted from "
                  << "(" << x1 << ", "
                  << y1 << ")"
                  << " to "
                  << "(" << x2 << ", " << y2 << ")" << std::endl;
        Line(x1,x2,y1,y2).draw(GREEN);
    }
    else
        std::cout << "Line rejected" << std::endl;
}

// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
bool clipLine(Line *l, Window w)
{
    // Compute region codes for P1, P2
    l->setcode(w);
    // int code1 = stoi(l->code1, 0, 2);
    // int code2 = stoi(l->code2, 0, 2);
    int code1 = setPointCode(l->p1, w);
    int code2 = setPointCode(l->p2, w);
    // string code2 = l->code2;
    double x1 = l->p1.x;
    double y1 = l->p1.y;
    double x2 = l->p2.x;
    double y2 = l->p2.y;

    int x_max = w.p3.x;
    int y_max = w.p3.y;
    int x_min = w.p1.x;
    int y_min = w.p1.y;

    // int x1 = l->p1.x;
    // int y1 = l->p1.y;
    // int x2 = l->p2.x;
    // int y2 = l->p2.y;
    int cont = 0;

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
            // string out_code;
            double x, y;
            bool is_first;

            cout << code1 << " " << code2 << " " << code_out << endl;
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            if (cont > 5)
            {
                break;
            }
            cont++;

            // At least one endpoint is outside the rectangle, pick it.
            if (code1 != 0)
            {
                is_first = true;
                code_out = code1;
            }
            else
            {
                is_first = false;
                code_out = code2;
            }

            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            /*
                        // Find intersection point
                        double slope = (y2 - y1) / (x2 - x1);
                        if (code_out & TOP)
                        // if (out_code[0] == '1')
                        {
                            // point is above the clip rectangle
                            if (is_first)
                            {
                                x = x1 + (w.p1.y - y1) / slope;
                            }
                            else
                            {
                                x = x2 + (w.p1.y - y2) / slope;
                            }
                            y = w.p3.y;
                        }
                        else if (code_out & BOTTOM)
                        // else if (out_code[1] == '1')
                        {
                            // point is below the rectangle
                            if (is_first)
                            {
                                x = x1 + (w.p3.y - y1) / slope;
                            }
                            else
                            {
                                x = x2 + (w.p3.y - y2) / slope;
                            }
                            y = w.p1.y;
                        }
                        else if (code_out & RIGHT)
                        // else if (out_code[2] == '1')
                        {
                            // point is to the right of rectangle
                            if (is_first)
                            {
                                y = y1 + (w.p3.x - x1) * slope;
                            }
                            else
                            {
                                y = y2 + (w.p3.x - x2) * slope;
                            }
                            x = w.p3.x;
                        }
                        else if (code_out & LEFT)
                        // else if (out_code[3] == '1')
                        {
                            // point is to the left of rectangle
                            if (is_first)
                            {
                                y = y1 + (w.p1.x - x1) * slope;
                            }
                            else
                            {
                                y = y2 + (w.p1.x - x2) * slope;
                            }
                            x = w.p1.x;
                        }
            */
            // Now intersection point x, y is found
            if (is_first)
            {
                x1 = x;
                y1 = y;
                // code1 = stoi(setpntcode(p1, w), 0, 2);
                code1 = setPointCode(Point((x1, y1)), w);
            }
            else
            {
                x2 = x;
                y2 = y;
                // code2 = stoi(setpntcode(p1, w), 0, 2);
                code2 = setPointCode(Point((x2, y2)), w);
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
        return false;
    }
}

// Driver code
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // initialize graph
    Line linearr[10];
    Point p1, p3;
    int n;
    delay(1000);

    cout << "Enter starting coordinates of window(p1):";
    cin >> p1.x >> p1.y;
    cout << "Enter Ending coordinates of window(p3):";
    cin >> p3.x >> p3.y;

    cout << "Enter number of lines:";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter line (x1,y1,x2,y2)" << i + 1 << " :";
        cin >> linearr[i].p1.x >> linearr[i].p1.y >> linearr[i].p2.x >> linearr[i].p2.y;
    }

    Window w1(p1, p3);
    w1.draw(YELLOW);

    x_max = w1.p3.x;
    y_max = w1.p3.y;
    x_min = w1.p1.x;
    y_min = w1.p1.y;

    for (int i = 0; i < n; i++)
        linearr[i].draw(RED);

    cout << "Cliping in 3 seconds" << endl;
    delay(3000);
    // cleardevice();
    w1.draw(YELLOW);

    for (int i = 0; i < n; i++)
    {
        if (clipLine(&linearr[i], w1))
        {
            linearr[i].draw(GREEN);
        }
    }

    cout << "End";
    getch();
    closegraph();
    return 0;
}

/*
100 100 300 300
4
150 50 150 120
50 150 150 120
120 160 350 250
150 150 200 150

*/