#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;
// algo simple for slope 0 to 1
void bresenhum_line1(int x1, int y1, int x2, int y2)
{
    int x, y, dx, dy, p;
    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 * dy - dx;
    while (x <= x2)
    {
        putpixel(x, y, RED);
        x++;
        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            p = p + 2 * dy - 2 * dx;
            y++;
        }
    }
}

// all class algo
int sign(int a)
{
    if (a < 0)
        return -1;
    else
        return 1;
}

void bresenhum_line(int x1, int y1, int x2, int y2)
{
    int x, y, dx, dy, sx, sy, e;
    bool interchange;
    x = x1;
    y = y1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    sx = sign(x2 - x1);
    sy = sign(y2 - y1);
    if (dy > dx)
    {
        int temp = dy;
        dy = dx;
        dx = temp;
        delete &temp;
        interchange = true;
    }
    else
    {
        interchange = false;
    }
    e = 2 * dy - dx;

    for (int i = 0; i < dx; i++)
    {
        putpixel(x, y, RED);
        while (e > 0)
        {
            if (interchange)
            {
                x += sx;
            }
            else
            {
                y += sy;
            }
            e -= 2 * dx;
        }
        if (interchange)
        {
            y += sy;
        }
        else
        {
            x += sx;
        }
        e += 2 * dy;
    }
}

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    bresenhum_line(250, 250, 50, 100);
    getch();
    closegraph();

    return 0;
}
