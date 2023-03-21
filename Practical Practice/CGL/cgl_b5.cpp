/*
Write C++ program to draw a concave polygon and fill it with desired color using
scan fill algorithm. Apply the concept of inheritance.
*/

#include <graphics.h>

#include <algorithm>
#include <iostream>
using namespace std;

void koach_curve(double x1, double y1, double x2, double y2, int iter) {
    if (iter == 0) {
        line(x1, y1, x2, y2);
        return;
    }
    float x3, y3, x4, y4, x5, y5;

    x3 = (x1 * 2 + x2) / 3;
    y3 = (y1 * 2 + y2) / 3;

    x4 = (x2 * 2 + x1) / 3;
    y4 = (y2 * 2 + y1) / 3;

    double sin60 = 0.866;
    double cos60 = 0.5;

    x5 = ((x4 - x3) * cos60 + (y4 - y3) * sin60) + x3;
    y5 = ((y4 - y3) * cos60 - (x4 - x3) * sin60) + y3;

    koach_curve(x1, y1, x3, y3, iter - 1);
    koach_curve(x3, y3, x5, y5, iter - 1);
    koach_curve(x5, y5, x4, y4, iter - 1);
    koach_curve(x4, y4, x2, y2, iter - 1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    koach_curve(50, 300, 250, 50, 5);

    getch();
    closegraph();
    return 0;
}
