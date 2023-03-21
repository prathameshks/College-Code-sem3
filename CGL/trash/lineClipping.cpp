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

bool stringAND(string s1,string s2,int len=4){
    for (int i = 0; i < len; i++)
    {
        if ((s1[i]=='1') and (s2[i]=='1'))
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
        code1 = setpntcode(p1, w);
        code2 = setpntcode(p2, w);
    }
};

// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
bool clipLine(Line *l, Window w)
{
    // Compute region codes for P1, P2
    l->setcode(w);
    // int code1 = stoi(l->code1, 0, 2);
    // int code2 = stoi(l->code2, 0, 2);
    string code1 = l->code1;
    string code2 = l->code2;
    double x1 = l->p1.x;
    double y1 = l->p1.y;
    double x2 = l->p2.x;
    double y2 = l->p2.y;

    // Initialize line as outside the rectangular window
    bool accept = false;

    while (true)
    {
        if ((code1 == "0000") && (code2 == "0000"))
        {
            // If both endpoints lie within rectangle
            accept = true;
            break;
        }
        else if (stringAND(code1 , code2))
        {
            // If both endpoints are outside rectangle, in same region
            break;
        }
        else
        {
            // Some segment of line lies within the rectangle
            // int code_out;
            string out_code;
            double x, y;

            // At least one endpoint is outside the rectangle, pick it.
            if (code1 != "0000")
                out_code = l->code1;
                // code_out = code1;
            else
                out_code = l->code2;
                // code_out = code2;

            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            // if (code_out & TOP)
            if(out_code[0] == '1')
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (w.p3.y - y1) / (y2 - y1);
                y = w.p3.y;
            }
            // if (code_out & BOTTOM)
            else if(out_code[1] == '1')
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (w.p1.y - y1) / (y2 - y1);
                y = w.p1.y;
            }
            // if (code_out & RIGHT)
            else if(out_code[2] == '1')
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (w.p3.x - x1) / (x2 - x1);
                x = w.p3.x;
            }
            // if (code_out & LEFT)
            else if(out_code[3] == '1')
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (w.p1.x - x1) / (x2 - x1);
                x = w.p1.x;
            }

            // Now intersection point x, y is found
            if (out_code == code1)
            {
                x1 = x;
                y1 = y;
                Point p1(x1, y1);
                // code1 = stoi(setpntcode(p1, w), 0, 2);
                code1 = setpntcode(p1, w);
            }
            else
            {
                x2 = x;
                y2 = y;
                Point p1(x2, y2);
                // code2 = stoi(setpntcode(p1, w), 0, 2);
                code2 = setpntcode(p1, w);
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
    Point p1,p3;
    int n;
    delay(1000);
    
    cout<<"Enter starting coordinates of window(p1):";
    cin>>p1.x>>p1.y;
    cout<<"Enter Ending coordinates of window(p3):";
    cin>>p3.x>>p3.y;

    cout<<"Enter number of lines:";
    cin>>n;

    for (int i = 0; i < n; i++){
        cout<<"Enter line (x1,y1,x2,y2)"<<i+1<<" :";
        cin>>linearr[i].p1.x>>linearr[i].p1.y>>linearr[i].p2.x>>linearr[i].p2.y;
    }

    Window w1(p1, p3);
    w1.draw(YELLOW);

    for (int i = 0; i < 3; i++)
        linearr[i].draw(RED);

    cout<<"Cliping in 3 seconds"<<endl;
    delay(3000);
    // cleardevice();
    w1.draw(YELLOW,0);

    for (int i = 0; i < 3; i++)
    {
        if (clipLine(&linearr[i], w1))
        {
            linearr[i].draw(GREEN);
        }
    }

    cout<<"End";
    getch();
    closegraph();
    return 0;
}

/*
100 100 300 300
3
50 50 150 120
120 160 350 250
150 150 200 150

*/