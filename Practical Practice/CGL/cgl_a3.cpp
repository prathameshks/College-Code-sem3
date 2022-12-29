/*
Write C++ program to draw the following pattern. Use DDA line and Bresenham's
circle drawing algorithm. Apply the concept Of encapsulation.
*/

#include <graphics.h>
#include <math.h>

#include <iostream>

using namespace std;

// digital defferential analizer
void dda_line(int x1, int y1, int x2, int y2) {
    double dx, dy;
    double xincr, yincr, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    int step = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    xincr = (dx) / step;
    yincr = (dy) / step;

    x = x1;
    y = y1;

    for (int i = 0; i < step + 1; i++) {
        putpixel(x, y, RED);
        x += xincr;
        y += yincr;
    }
}

void circlePoint(int xc, int yc, double x, double y) {
    putpixel(xc + x, yc + y, RED);
    putpixel(xc + y, yc + x, RED);

    putpixel(xc - x, yc + y, RED);
    putpixel(xc - y, yc + x, RED);

    putpixel(xc - x, yc - y, RED);
    putpixel(xc - y, yc - x, RED);

    putpixel(xc + x, yc - y, RED);
    putpixel(xc + y, yc - x, RED);
}

void bresenhm_circle(int xc, int yc, int radius) {
    double x, y;
    x = 0;
    y = radius;
    circlePoint(xc, yc, x, y);
    int p = 3 - 2 * radius;
    while (x <= y) {
        x++;
        if (p <= 0) {
            p += 4 * x + 6;
        } else {
            y--;
            p += 4 * (x - y) + 10;
        }
        circlePoint(xc, yc, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    getch();
    closegraph();
    return 0;
}