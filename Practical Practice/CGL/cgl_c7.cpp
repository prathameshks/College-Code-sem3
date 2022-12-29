/*
Write C++ program to draw a concave polygon and fill it with desired color using
scan fill algorithm. Apply the concept of inheritance.
*/

#include <graphics.h>

#include <algorithm>
#include <iostream>
using namespace std;

void rain(int width, int height) {
    for (int i = 0; i < 300; i++) {
        int x = rand() % width;
        int y = rand() % height;
        line(x, y, x + 1, y + 2);
    }
}

void man(int x, int y) {
    circle(x + 10, y - 10, 7);
    line(x + 10, y - 3, x + 10, y);
    rectangle(x, y, x + 20, y + 50);
    line(x, y, x - 10, y + 30);
    line(x + 20, y, x + 25, y + 15);
    line(x + 25, y + 15, x + 30, y);
    line(x + 30, y, x + 30, y - 50);
    arc(x + 30, y - 50, 180, 0, 45);
    line(x - 15, y - 50, x + 75, y - 50);

    y += 50;
    line(x + 2, y, x + 2, y + 50);
    line(x + 18, y, x + 18, y + 50);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    for (int i = 20; i < 500; i += 5) {
        line(0, 400, 600, 400);  // ground
        man(i, 300);
        rain(600, 400);
        cleardevice();
    }

    getch();
    closegraph();
    return 0;
}
