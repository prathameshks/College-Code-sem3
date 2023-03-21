/*
Write C++ program to draw a concave polygon and fill it with desired color using
scan fill algorithm. Apply the concept of inheritance.
*/

#include <graphics.h>

#include <algorithm>
#include <iostream>
using namespace std;

class point {
   public:
    int x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(int a, int b) {
        x = a;
        y = b;
    }
    bool operator==(point p) { return (x == p.x && y == p.y); }
};

class Line {
    // small y coord is at p1
   public:
    point p1, p2;
    double dx, dy, m;
    void create(point p1, point p2) {
        if (p1.y > p2.y) {
            this->p2 = p1;
            this->p1 = p2;
        } else {
            this->p1 = p1;
            this->p2 = p2;
        }
        dx = p2.x - p1.x;
        dy = p2.y - p1.y;
        if (dx == 0) {
            m = 1;
        } else if (dy == 0) {
            m = 0;
        } else {
            m = dy / dx;
        }
    }
    int intersect(int y_cord) {
        if (y_cord < p1.y || y_cord > p2.y) {
            return 0;
        } else {
            int x_cord = ((y_cord - p1.y) / m) + p1.x;
            return x_cord;
        }
    }
    void draw() { line(p1.x, p1.y, p2.x, p2.y); }
};

class polygon {
   public:
    Line edges[11];
    int xcords[11];
    int ycords[11];
    int n, ymin, ymax;
    void create() {
        cout << "Enter number of vertices(3-10):";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter x and y " << i + 1 << ":";
            cin >> xcords[i] >> ycords[i];
        }
        xcords[n] = xcords[0];
        ycords[n] = ycords[0];
        ymin = ycords[0];
        ymax = ycords[0];
        for (int i = 0; i < n; i++) {
            edges[i].create(point(xcords[i], ycords[i]),
                            point(xcords[i + 1], ycords[i + 1]));
            if (ycords[i] < ymin) {
                ymin = ycords[i];
            }
            if (ycords[i] > ymax) {
                ymax = ycords[i];
            }
        }
    }

    void draw() {
        for (int i = 0; i < n; i++) {
            edges[i].draw();
        }
    }
};

void scan_fill() {
    polygon poly;
    poly.create();

    poly.draw();
    setcolor(RED);

    delay(200);

    for (int yscan = poly.ymin; yscan <= poly.ymax; yscan++) {
        delay(20);
        double xintersects[10];
        int n = 0;
        for (int j = 0; j < poly.n; j++) {
            int xscan = poly.edges[j].intersect(yscan);

            if (xscan != 0) {
                int next = (j + 1) % poly.n;
                // excess condition } else if (yscan == poly.edges[j].p2.y) {
                if (yscan == poly.edges[j].p1.y) {
                    if (poly.edges[next].p2 == poly.edges[j].p1 ||
                        poly.edges[next].p1 == poly.edges[j].p2) {
                        // skip this point
                    }
                } else {
                    xintersects[n] = xscan;
                    n++;
                }
            }
        }
        sort(xintersects, xintersects + n);
        for (int k = 0; k < n; k += 2) {
            line(xintersects[k], yscan, xintersects[k + 1], yscan);
        }
    }
}

int main() {
    // int x1 = 10, x2 = 40;
    // int y1 = 10, y2 = 100;
    // Line l1;
    // l1.create(point(x1, y1), point(x2, y2));

    // for (int i = 8; i < 102; i++) {
    //     cout << l1.intersect(i) << endl;
    // }
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    scan_fill();

    getch();
    closegraph();
    return 0;
}

/*
very complex
10
10 10 120 8 110 100 90 90 100 30 30 35 25 70 70 45 40 90 15 80

5
80 20 100 80 150 60 130 200 40 250

6
50 50 100 50 120 120 80 80 50 120 40 60

*/