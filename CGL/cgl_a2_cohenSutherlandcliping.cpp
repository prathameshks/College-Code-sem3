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

// DDA Line algorithm to draw line
void drawline(int x1, int y1, int x2, int y2, _color col = RED, int Delay = 1)
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
        delay(Delay);

        putpixel(round(x), round(y), col);
        x += x_incr;
        y += y_incr;
    }
}

// line class with point p1 and p2
class Line
{
public:
    // int code1 = -1, code2 = -1;
    double x1, y1, x2, y2;

    Line(double x1, double y1, double x2, double y2)
    {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    Line()
    {
    }

    void draw(_color col = RED, int Delay = 1)
    {
        drawline(x1, y1, x2, y2, col, Delay);
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

void cohenSutherland(double x1, double y1, double x2, double y2)
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

                  drawline(x1,y1,x2,y2,GREEN);
    }
    else
        std::cout << "Line rejected" << std::endl;
}
// Driver code
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // initialize graph
    Line linearr[10];
    int n;
    delay(1000);

    cout << "Enter starting coordinates of window(p1):";
    cin >> x_min >> y_min;
    cout << "Enter Ending coordinates of window(p3):";
    cin >> x_max >> y_max;

    cout << "Enter number of lines:";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter line (x1,y1,x2,y2)" << i + 1 << " :";
        cin >> linearr[i].x1 >> linearr[i].y1 >> linearr[i].x2 >> linearr[i].y2;
    }

    // draw window
    drawline(x_min, y_min, x_max, y_min);
    drawline(x_max, y_min, x_max, y_max);
    drawline(x_max, y_max, x_min, y_max);
    drawline(x_min, y_max, x_min, y_min);

    for (int i = 0; i < n; i++)
        linearr[i].draw(RED);

    cout << "Cliping in 3 seconds" << endl;
    delay(3000);
    // cleardevice();

    for (int i = 0; i < n; i++)
    {
        cohenSutherland(linearr[i].x1, linearr[i].y1, linearr[i].x2, linearr[i].y2);
    }

    cout << "End";
    getch();
    closegraph();
    return 0;
}

/*
100 100 300 300
4
50 50 150 120
50 150 150 120
120 160 350 250
150 150 200 150

*/

// void cohenSutherland2(int x1, int y1, int x2, int y2, Line l)
// {
//     int code1 = generateCode(l.x1, l.y1); // Compute region codes for P1.
//     int code2 = generateCode(l.x2, l.y2); // Compute region codes for P2.
//     bool accept = false;                  // Initialize line as outside the rectangular window.
//     while (true)
//     {
//         if ((code1 == 0) && (code2 == 0))
//         {
//             // If both endpoints lie within rectangle.
//             accept = true;
//             break;
//         }
//         else if (code1 & code2)
//         {
//             // If both endpoints are outside rectangle,in same region.
//             break;
//         }
//         else
//         {
//             // Some segment of line lies within the rectangle.
//             int code_out;
//             double x, y;
//             // At least one endpoint lies outside the rectangle, pick it.
//             if (code1 != 0)
//                 code_out = code1;
//             else
//                 code_out = code2;
//             /*
//              * Find intersection point by using formulae :
//              y = l.y1 + slope * (x - l.x1)
//              x = l.x1 + (1 / slope) * (y - l.y1)
//              */
//             if (code_out & TOP)
//             {
//                 // point is above the clip rectangle
//                 x = l.x1 + (l.x2 - l.x1) * (y_max - l.y1) / (l.y2 - l.y1);
//                 y = y_max;
//             }
//             else if (code_out & BOTTOM)
//             {
//                 // point is below the rectangle
//                 x = l.x1 + (l.x2 - l.x1) * (y_min - l.y1) / (l.y2 - l.y1);
//                 y = y_min;
//             }
//             else if (code_out & RIGHT)
//             {
//                 // point is to the right of rectangle
//                 y = l.y1 + (l.y2 - l.y1) * (x_max - l.x1) / (l.x2 - l.x1);
//                 x = x_max;
//             }
//             else if (code_out & LEFT)
//             {
//                 // point is to the left of rectangle
//                 y = l.y1 + (l.y2 - l.y1) * (x_min - l.x1) / (l.x2 - l.x1);
//                 x = x_min;
//             }
//             // Intersection point x,y is found.
//             // Replace point outside rectangle by intersection point.
//             if (code_out == code1)
//             {
//                 l.x1 = x;
//                 l.y1 = y;
//                 code1 = generateCode(l.x1, l.y1);
//             }
//             else
//             {
//                 l.x2 = x;
//                 l.y2 = y;
//                 code2 = generateCode(l.x2, l.y2);
//             }
//         }
//     }
//     if (accept)
//     {
//         std::cout << "Line accepted from "
//                   << "(" << l.x1 << ", "
//                   << l.y1 << ")"
//                   << " to "
//                   << "(" << l.x2 << ", " << l.y2 << ")" << std::endl;
//         Line(l.x1, l.x2, l.y1, l.y2).draw(GREEN);
//     }
//     else
//         std::cout << "Line rejected" << std::endl;
// }
