#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

class Window;
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

class Line
{
public:
    string code1, code2;
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
    void displaycode(){
        cout<<code1<<" & "<<code2<<endl;
    }
};
void Drawline(Point p1, Point p2)
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
        delay(1);

        putpixel(round(x), round(y), RED);
        x += x_incr;
        y += y_incr;
        // delay(10);
    }
}
void Drawline(Line l1)
{
    // Calculate dx and dy
    Point p1 = l1.p1;
    Point p2 = l1.p2;
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
        delay(1);

        putpixel(round(x), round(y), RED);
        x += x_incr;
        y += y_incr;
        // delay(10);
    }
}

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
    void Draw()
    {
        Drawline(p1, p2);
        Drawline(p2, p3);
        Drawline(p3, p4);
        Drawline(p4, p1);
    }

    void Display_coords()
    {
        cout << p1.x << " " << p1.y << endl;
        cout << p2.x << " " << p2.y << endl;
        cout << p3.x << " " << p3.y << endl;
        cout << p4.x << " " << p4.y << endl;
    }

    void setcode(Line l){
        //top bottom right left
        //for p1
        string code1 = "0000";
        if (l.p1.x< p1.x){
            code1[2] = '1';
        }
        if (l.p1.x> p2.x)
        {
            code1[3]='1';
        }
        if (l.p1.y< p1.y){
            code1[0] = '1';
        }
        if (l.p1.y> p4.y)
        {
            code1[1]='1';
        }
        l.code1 = code1;
        
        //for p2
        string code2 = "0000";
        if (l.p2.x< p1.x){
            code2[2] = '1';
        }
        if (l.p2.x> p2.x)
        {
            code2[3]='1';
        }
        if (l.p2.y< p1.y){
            code2[0] = '1';
        }
        if (l.p2.y> p4.y)
        {
            code2[1]='1';
        }
        l.code2 = code2;
        
    }
};

// Driver code
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // initialize graph

    Point p1(100, 100), p2(300, 100), p3(300, 200), p4(100, 200);
    Window w1(p1, p2, p3, p4);
    w1.Draw();
    // w1.Display_coords();
    Window w2(p1, p3);
    w2.Draw();
    // w2.Display_coords();
    Line l1(50,150,250,70);
    Drawline(l1);
    w1.setcode(l1);
    l1.displaycode();
    getch();
    closegraph();
    return 0;
}