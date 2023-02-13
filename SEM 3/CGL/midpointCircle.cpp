#include <graphics.h>

#include <iostream>
using namespace std;

void draw(int xc, int yc, int x, int y, _color c = RED) {
    putpixel(xc + x, yc + y, c);
    putpixel(xc + y, yc + x, c);
    putpixel(xc + x, yc - y, c);
    putpixel(xc + y, yc - x, c);
    putpixel(xc - x, yc + y, c);
    putpixel(xc - y, yc + x, c);
    putpixel(xc - x, yc - y, c);
    putpixel(xc - y, yc - x, c);
}

void midpointCircle(int xc, int yc, int r) {
    int x = r;
    int y = 0;
    int p = 1 - r;
    while (x >= y) {
        draw(xc, yc, x, y);
        y++;
        if (p <= 0) {
            p += (2 * y + 1);
        } else {
            x--;
            p += (2 * (y - x) + 1);
        }
    }
}

int main() {
    int gdriver = DETECT, gmode, error, x, y, r;
    initgraph(&gdriver, &gmode, NULL);

    setcolor(RED);
    setcolor(BLUE);
    circle(100, 100, 60);

    // cout << "Enter radius of circle: ";
    // cin >> r;

    // cout << "Enter co-ordinates of center(x and y): ";
    // cin >> x >> y;
    // drawcircle(x, y, r);
    midpointCircle(100, 100, 60);

    getch();
    closegraph();

    return 0;
}