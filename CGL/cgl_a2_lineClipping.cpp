#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

class Line;
class Window{
    public:
    Line left,right,top,bottom;
    void Draw(){
        left.Draw();
        right.Draw();
        top.Draw();
        bottom.Draw();
    }

};

class Line
{
public:
    int x1, x2, y1, y2;
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
    string getcode()
    {

    }
};

// Driver code
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // initialize graph

    getch();
    closegraph();
    return 0;
}