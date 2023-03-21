#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;
// algo simple for slope 0 to 1
void bresenhum_line(int x1, int y1, int x2, int y2)
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


int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    bresenhum_line(50, 50, 250, 100);
    getch();
    closegraph();

    return 0;
}
