#include <iostream>
#include <math.h>
#include <graphics.h>
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

bool clipline(Line l, Window w)
{
    // set code to endpoint if not set already
    string clipCode;
    if (l.code1 == "" or l.code2 == "")
    {
        l.setcode(w);
    }
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
        clipCode = (l.code1 == "0000") ? l.code2 : clipCode = l.code1;
        for (int code = 0; code < 4; code++)
        {
            if (clipCode[code]=='1')
            {
                
            }
            
        }
        
        return true;
    }
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
    Window w2(p1, p3);
    w2.draw(YELLOW, 10);
    // w2.Display_coords();
    Line l1(50, 150, 250, 70);
    l1.draw(GREEN, 0);
    l1.displaycode();
    l1.setcode(w1);
    l1.displaycode();
    getch();
    closegraph();
    return 0;
}