/*
Write C++ program to draw a concave polygon and fill it with desired color using
scan fill algorithm. Apply the concept of inheritance.
*/

// NOT WORKING


/*
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

void move(int j, int h, int &x, int &y) {
    if (j == 1)
        y -= h;
    else if (j == 2)
        x += h;
    else if (j == 3)
        y += h;
    else if (j == 4)
        x -= h;
    lineto(x, y);
}

void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y) {
    if (i > 0) {
        i--;
        hilbert(d, r, u, l, i, h, x, y);
        move(r, h, x, y);
        hilbert(r, d, l, u, i, h, x, y);
        move(d, h, x, y);
        hilbert(r, d, l, u, i, h, x, y);
        move(l, h, x, y);
        hilbert(u, l, d, r, i, h, x, y);
    }
}

int main() {
    int n, x1, y1;
    int x0 = 50, y0 = 150, x, y, h = 10, r = 2, d = 3, l = 4, u = 1;

    cout << "\nGive the value of n: ";
    cin >> n;
    x = x0;
    y = y0;
    int gm, gd = DETECT;
    initgraph(&gd, &gm, NULL);
    moveto(x, y);
    hilbert(r, d, l, u, n, h, x, y);
    getch();

    closegraph();

    return 0;
}


*/


#include <graphics.h>

#include <algorithm>
#include <iostream>
using namespace std;

enum dir { LEFT, RIGHT, BOTTOM, TOP };

void move_to(dir type, double l, double &x, double &y) {
    if (type == LEFT) {
        line(x, y, x - l, y);
        x = x - l;
    } else if (type == RIGHT) {
        line(x, y, x + l, y);
        x = x + l;
    } else if (type == TOP) {
        line(x, y, x, y - l);
        y = y - l;
    } else if (type == BOTTOM) {
        line(x, y, x, y + l);
        y = y + l;
    }
}

void hilbert(double x1, double y1, double x2, double y2, dir type, int iter) {
    if (iter == 0) {
        if (type == LEFT) {
            line(x1, y1, x2, y1);
            line(x2, y1, x2, y2);
            line(x2, y2, x1, y2);
            // line(x1, y2, x1, y1);
        } else if (type == RIGHT) {
            line(x1, y1, x2, y1);
            // line(x2, y1, x2, y2);
            line(x2, y2, x1, y2);
            line(x1, y2, x1, y1);
        } else if (type == TOP) {
            // line(x1, y1, x2, y1);
            line(x2, y1, x2, y2);
            line(x2, y2, x1, y2);
            line(x1, y2, x1, y1);
        } else if (type == BOTTOM) {
            line(x1, y1, x2, y1);
            line(x2, y1, x2, y2);
            // line(x2, y2, x1, y2);
            line(x1, y2, x1, y1);
        }
        return;
    }

    double part = (x2 - x1) / 3;

    if (type == LEFT) {
        line(x1, y1, x2, y1);
        line(x2, y1, x2, y2);
        line(x2, y2, x1, y2);
        // line(x1, y2, x1, y1);
    } else if (type == RIGHT) {
        line(x1, y1, x2, y1);
        // line(x2, y1, x2, y2);
        line(x2, y2, x1, y2);
        line(x1, y2, x1, y1);
    } else if (type == TOP) {
        hilbert(x1, y1, x1 + part, y1 + part, LEFT, iter - 1);
        move_to(BOTTOM,part)
        line(x1, y1 + part, x1, y2 - part);
        hilbert(x1, y2 - part, x1 + part, y2, TOP, iter - 1);

        hilbert(x1, y1, x1 + part, y1 + part, LEFT, iter - 1);
        hilbert(x1, y1, x1 + part, y1 + part, LEFT, iter - 1);
    } else if (type == BOTTOM) {
        line(x1, y1, x2, y1);
        line(x2, y1, x2, y2);
        // line(x2, y2, x1, y2);
        line(x1, y2, x1, y1);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    getch();
    closegraph();
    return 0;
}
