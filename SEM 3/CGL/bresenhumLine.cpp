#include <graphics.h>
#include <math.h>

#include <iostream>

using namespace std;

void b_line(int x2, int y2, int x1, int y1) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1, y = y1;
    int p = 2 * dy - dx;
    int sx = (x1 > x2) ? -1 : 1;
    int sy = (y1 > y2) ? -1 : 1;
    int interchange = 0;
    if (dy > dx) {
        // int temp = dy;
        // dy = dx;
        // dx = temp;
        // delete &temp;
        interchange = 1;
    }

    while (x != x2) {
        putpixel(x, y, RED);
        if (interchange) {
            if (p < 0) {
                p += 2 * dx;
            } else {
                x+=sx;
                p += (2 * dx - 2 * dy);
            }
            y+=sy;
        } else {
            if (p < 0) {
                p += 2 * dy;
            } else {
                y+=sy;
                p += (2 * dy - 2 * dx);
            }
            x+=sx;
        }
    }
}

int main() {
    int gm, gd = DETECT;
    initgraph(&gd, &gm, NULL);

    b_line(50,50,250,100);
    b_line(70,70,150,300);

    getch();
    closegraph();

    return 0;
}