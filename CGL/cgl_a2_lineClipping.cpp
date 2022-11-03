#include <iostream>
#include <math.h>
#include <graphics.h>
#include<string>
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

    Point intersection(Point wp1, Point wp2)
    {
        Point res;
        res.x = ((wp1.x * wp2.y - wp1.y * wp2.x) * (p1.x - p2.x)) - ((p1.x * p2.y - p1.y * p2.x) * (wp1.x - wp2.x)) / ((wp1.x - wp2.x) * (p1.y - p2.y) - (wp1.y - wp2.y) * (p1.x - p2.x));
        res.y = ((wp1.x * wp2.y - wp1.y * wp2.x) * (p1.y - p2.y)) - ((p1.x * p2.y - p1.y * p2.x) * (wp1.y - wp2.y)) / ((wp1.x - wp2.x) * (p1.y - p2.y) - (wp1.y - wp2.y) * (p1.x - p2.x));
        // if (res.x < wp1.x or res.x > wp2.x)
        // {
        //     res.x = -1;
        // }
        // if (res.y < wp1.y or res.y > wp2.y)
        // {
        //     res.y = -1;
        // }
        return res;
    }

    void setcode(Window w)
    {
        // top bottom right left
        string tmpcode1 = "0000", tmpcode2 = "0000";

        // for p1
        if (p1.x < w.p1.x)
            tmpcode1[3] = '1';
        if (p1.x > w.p2.x)
            tmpcode1[2] = '1';
        if (p1.y < w.p1.y)
            tmpcode1[0] = '1';
        if (p1.y > w.p4.y)
            tmpcode1[1] = '1';

        // for p2
        if (p2.x < w.p1.x)
            tmpcode2[3] = '1';
        if (p2.x > w.p2.x)
            tmpcode2[2] = '1';
        if (p2.y < w.p1.y)
            tmpcode2[0] = '1';
        if (p2.y > w.p4.y)
            tmpcode2[1] = '1';

        code1 = tmpcode1;
        code2 = tmpcode2;
    }
};

bool logicalAnd(string s1, string s2)
{
    for (int i = 0; i < 4; i++)
    {
        if (s1[i] == '1' and s2[i] == '1')
        {
            return true;
        }
    }
    return false;
}

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
// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
bool cohenSutherlandClip(Line *l, Window w,Line * res)
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
            // If both endpoints are outside rectangle,
            // in same region
            break;
        }
        else
        {
            // Some segment of line lies within the
            // rectangle
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

                code1 = stoi(setpntcode(p1,w), 0, 2);
            }
            else
            {
                x2 = x;
                y2 = y;
                Point p1(x2, y2);

                code2 = stoi(setpntcode(p1,w), 0, 2);
            }
        }
    }
    if (accept)
    {
        //set new line points
        l->p1.x = x1;
        l->p1.y = y1;
        l->p2.y = y2;
        l->p2.x = x2;
        return true;
    }
    else{
        // cout << "Line rejected" << endl;
        return false;
        }
}

bool clipline(Line l, Window w)
{
    // set code to endpoint if not set already
    string clipCode;
    Point res;
    bool first, isset = false;
    // if (l.code1 == "" or l.code2 == "")
    // {
    // }
    l.setcode(w);
    // if both end are inside window then no need to clip
    if (l.code1 == "0000" and l.code2 == "0000")
    {
        return true;
    }

    // if and of codes is non zero then completely outside
    if (logicalAnd(l.code1, l.code2))
    {
        return false;
    }
    // if one point is inside and one is outside
    if (l.code1 == "0000" or l.code2 == "0000")
    {
        /*debug*/ cout << "Reached Start " << endl;
        clipCode = (l.code1 == "0000") ? l.code2 : l.code1;
        first = (l.code1 == "0000") ? false : true;
        if (clipCode[0] == '1' and not isset)
        {
            // top
            res = l.intersection(w.p1, w.p2);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                if (first)
                    l.p1 = res;
                else
                    l.p2 = res;
            }
        }
        if (clipCode[1] == '1' and not isset)
        {
            // bottom
            res = l.intersection(w.p4, w.p3);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                if (first)
                    l.p1 = res;
                else
                    l.p2 = res;
            }
        }
        if (clipCode[2] == '1' and not isset)
        {
            // right
            res = l.intersection(w.p2, w.p3);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                if (first)
                    l.p1 = res;
                else
                    l.p2 = res;
            }
        }
        if (clipCode[3] == '1' and not isset)
        {
            /*debug*/ cout << "Reached Left " << endl;
            // left
            res = l.intersection(w.p1, w.p4);
            cout << res.x << res.y << endl;
            // if (res.x < wp1.x or res.x > wp2.x)
        // {
        //     res.x = -1;
        // }
        // if (res.y < wp1.y or res.y > wp2.y)
        // {
        //     res.y = -1;
        // }
            if ((res.x != -1) and (res.y != -1))
            {
                /*debug*/ cout << "Reached assign 1 " << endl;

                isset = true;
                if (first)
                    l.p1 = res;
                else
                    l.p2 = res;

                cout << res.x << res.y << endl;
            }
        }
        return true;
    }
    else
    {
        /*debug*/ cout << "Reached Start " << endl;
        // for 1st point
        isset = false;
        clipCode = l.code1;
        if (clipCode[0] == '1' and not isset)
        {
            // top
            res = l.intersection(w.p1, w.p2);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                l.p1 = res;
            }
        }
        if (clipCode[1] == '1' and not isset)
        {
            // bottom
            res = l.intersection(w.p4, w.p3);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                l.p1 = res;
            }
        }
        if (clipCode[2] == '1' and not isset)
        {
            // right
            res = l.intersection(w.p2, w.p3);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                l.p1 = res;
            }
        }
        if (clipCode[3] == '1' and not isset)
        {
            // left
            res = l.intersection(w.p1, w.p4);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                l.p1 = res;
            }
        }

        // for 2nd point
        isset = false;
        clipCode = l.code2;
        if (clipCode[0] == '1' and not isset)
        {
            // top
            res = l.intersection(w.p1, w.p2);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                l.p2 = res;
            }
        }
        if (clipCode[1] == '1' and not isset)
        {
            // bottom
            res = l.intersection(w.p4, w.p3);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                l.p2 = res;
            }
        }
        if (clipCode[2] == '1' and not isset)
        {
            // right
            res = l.intersection(w.p2, w.p3);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                l.p2 = res;
            }
        }
        if (clipCode[3] == '1' and not isset)
        {
            // left
            res = l.intersection(w.p1, w.p4);
            if (res.x != -1 and res.y != -1)
            {
                isset = true;
                l.p2 = res;
            }
        }
        l.draw(BLUE);
        return true;
    }
    cout << "Can Not clip" << endl;
    return false;
}

// Driver code
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // initialize graph

    Point p1(100, 100), p2(300, 100), p3(300, 200), p4(100, 200);
    Window w1(p1, p2, p3, p4);
    w1.draw();
    // w1.Display_coords();
    // Window w2(p1, p3);
    // w2.draw(YELLOW, 10);
    // w2.Display_coords();
    Line l1(50, 150, 150, 170);
    Line res(0,0,0,0);
    l1.draw(GREEN, 0);
    // l1.displaycode();
    // l1.setcode(w1);
    // l1.displaycode();
    // delay(2000);
    if (cohenSutherlandClip(&l1, w1,&res))
    {
        l1.draw(RED);
    }
    else
    {
        l1.draw(BLUE);
    }
    
    getch();
    closegraph();
    return 0;
}