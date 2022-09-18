#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

int sign(int a)
{
    if (a < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void line(int x1, int y1, int x2, int y2)
{
    int x, y, dx, dy, s1, s2;
    int interchange, e;
    x = x1;
    y = y1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    s1 = sign(x2 - x1);
    s2 = sign(y2 - y1);
    if (dy > dx)
    {
        int temp = dy;
        dy = dx;
        dx = temp;
        delete &temp;
        interchange = 1;
    }
    else
    {
        interchange = 0;
    }
    e = 2 * dy - dx;

    for (int i = 0; i <= dx * 4; i++)
    {
        if (i > dx)
        {
            putpixel(x, y, GREEN);
        }
        else
        {
            putpixel(x, y, RED);
        }
        while (e > 0)
        {
            if (interchange == 1)
            {
                x += s1;
            }
            else
            {
                y += s2;
            }
            e -= 2 * dy;
        }
        if (interchange == 1)
        {
            y += s2;
        }
        else
        {
            x += s1;
        }
        e -= 2 * dx;
    }
}

int main()
{
    int ix1, ix2, iy1, iy2;

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    cout << "Running init" << endl;

    cout << "Enter coords of start :";
    cin >> ix1 >> iy1;
    cout << "Enter coords of end :";
    cin >> ix2 >> iy2;

    line(ix1, iy1, ix2, iy2);
    int u;
    cin >> u;
    // delay(10000);

    closegraph();
    return 0;
}