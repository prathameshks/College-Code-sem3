#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

class Window;
class Point{
public:
int x,y;
Point(int a,int b){
    x=a;
    y=b;
}
Point(){
    x=0;
    y=0;
}
};

class Line
{
public:
    string code1,code2;
    Point p1,p2;
    int x1, x2, y1, y2;
    Line(Point p1,Point p2){
        this->p1 = p1;
        this->p2 = p2;
    }
    Line(int x1,int x2,int y1,int y2){
        p1 = Point(x1,y1);
        p2 = Point(x2,y2);
    }
    void Draw()
    {
        // Calculate dx and dy
        int dx = x2 - x1;
        int dy = y2 - y1;
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
        float x = x1;
        float y = y1;

        for (int i = 0; i < step; i++)
        {
            delay(1);

            putpixel(round(x), round(y), RED);
            x += x_incr;
            y += y_incr;
            // delay(10);
        }
    }

    void Draw(int x1,int x2,int y1,int y2)
    {
        // Calculate dx and dy
        int dx = x2 - x1;
        int dy = y2 - y1;
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
        float x = x1;
        float y = y1;

        for (int i = 0; i < step; i++)
        {
            delay(1);

            putpixel(round(x), round(y), RED);
            x += x_incr;
            y += y_incr;
            // delay(10);
        }
    }

    void Draw(Point p1, Point p2)
    {
        // Calculate dx and dy
        x1 = p1.x;
        y1 = p1.y;
        x2 = p2.x;
        y2 = p2.y;
        int dx = x2 - x1;
        int dy = y2 - y1;
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
        float x = x1;
        float y = y1;

        for (int i = 0; i < step; i++)
        {
            delay(1);

            putpixel(round(x), round(y), RED);
            x += x_incr;
            y += y_incr;
            // delay(10);
        }
    }
};


class Window{
    public:
    Point p1,p2,p3,p4;

    Window(Point p1,Point p2,Point p3,Point p4){
        //clockwise from top left
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
    }
    Window(){

    }
    Window(Point p1,Point p3){
        this->p1 = p1;
        this->p3 = p3;
        this->p2.x = p3.x;
        this->p2.y = p1.y;
        this->p4.x = p1.x;
        this->p4.y = p3.y;
    }
    void Draw(){
        Line *temp = new Line(p1,p2);
        temp->Draw(p1,p2);
        temp->Draw(p2,p3);
        temp->Draw(p3,p4);
        temp->Draw(p4,p1);
    }
    void Display_coords(){
        cout<<p1.x<<" "<<p1.y<<endl;
        cout<<p2.x<<" "<<p2.y<<endl;
        cout<<p3.x<<" "<<p3.y<<endl;
        cout<<p4.x<<" "<<p4.y<<endl;
    }
};


// Driver code
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // initialize graph

    Point p1(100,100),p2(300,100),p3(300,200),p4(100,200);
    Window w1(p1,p2,p3,p4);
    w1.Draw();
    w1.Display_coords();
Window w2(p1,p3);
    w2.Draw();
    w2.Display_coords();
    getch();
    closegraph();
    return 0;
}