#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, RED);
    putpixel(xc - x, yc + y, RED);
    putpixel(xc + x, yc - y, RED);
    putpixel(xc - x, yc - y, RED);
    putpixel(xc + y, yc + x, RED);
    putpixel(xc - y, yc + x, RED);
    putpixel(xc + y, yc - x, RED);
    putpixel(xc - y, yc - x, RED);
}

void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
        delay(10);
    }
}

void DDALine(int x0, int y0, int x1, int y1)
{
    // Calculate dx and dy
    int dx = x1 - x0;
    int dy = y1 - y0;
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
    float x = x0;
    float y = y0;

    for (int i = 0; i < step; i++)
    {
        delay(1);

        putpixel(round(x), round(y), RED);
        x += x_incr;
        y += y_incr;
        // delay(10);
    }
}

void pattern1(int x, int y, int r)
{
    int x1, y1, x2, y2, x3, y3, r1;
    x1 = x;
    y1 = y - r;
    x2 = x - (0.866 * r);
    x3 = x + (0.866 * r);
    y2 = y + r / 2;
    y3 = y + r / 2;
    r1 = r / 2;

    circleBres(x, y, r);

    DDALine(x1, y1, x2, y2);

    DDALine(x2, y2, x3, y3);

    DDALine(x3, y3, x1, y1);

    circleBres(x, y, r1);
}

void pattern2(int x1, int y1, int x2, int y2)
{
    // outer rectangle
    DDALine(x1, y1, x1, y2);
    DDALine(x1, y2, x2, y2);
    DDALine(x2, y2, x2, y1);
    DDALine(x2, y1, x1, y1);

    // center coords
    int xc = (x1 + x2) / 2;
    int yc = (y1 + y2) / 2;

    // inner rhombus
    DDALine(xc, y1, x1, yc);
    DDALine(x1, yc, xc, y2);
    DDALine(xc, y2, x2, yc);
    DDALine(x2, yc, xc, y1);

    // calculation of radius
    // int r = pow((pow((xc - xc), 2) + pow((yc - y1), 2)) * (pow((xc - x1), 2) + pow((yc - yc), 2)) / (pow((xc - x1), 2) + pow((y1 - yc), 2)), 0.5);
    double lx = pow((xc - x2), 2);
    double ly = pow((yc - y2), 2);

    int r = sqrt(ly * lx / (lx + ly));

    // draw circle
    circleBres(xc, yc, r);
}

// Driver code
int main()
{
    int ch;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // initialize graph

    int x, y, r;

    int x1, x2, y1, y2;
    delay(2000);
    cout << "Which Pattern You want to draw(1 or 2):";
    cin >> ch;
    if (ch == 1)
    {
        cout << "Enter coordinates of circle center:";
        cin >> x >> y;

        cout << "Enter radius of outer circle:";
        cin >> r;

        pattern1(x, y, r);
    }
    else if (ch == 2)
    {
        cout << "Enter coordinates of start:";
        cin >> x1 >> y1;

        cout << "Enter coordinates of End:";
        cin >> x2 >> y2;

        pattern2(x1, y1, x2, y2);
    }

    else
    {
        cout << "Enter a valid choice" << endl;
    }

    // pattern2(100, 100, 400, 250);
    getch();
    closegraph();
    return 0;
}

//link to folder https://mescoeorg-my.sharepoint.com/:f:/g/personal/f21111015_mescoeorg_onmicrosoft_com/Em4DXyPVuj9CnURtwz-t-2MBBCg2fmeiFtllFPOhk5TPfA?e=vIwhJe