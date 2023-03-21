/*
Write C++ program to implement Cohen Southerland line clipping algorithm.
*/

#include <graphics.h>

#include <iostream>

using namespace std;

// left right bottom top
int LEFT = 8;
int RIGHT = 4;
int BOTTOM = 2;
int TOP = 1;

class window {
   public:
    int xmin, ymin, xmax, ymax;

    int getcode(int x, int y) {
        int code = 0;
        if (x < xmin) code |= LEFT;
        if (x > xmax) code |= RIGHT;
        if (y < ymin) code |= TOP;
        if (y > ymax) code |= BOTTOM;
        return code;
    }

    void create() {
        cout << "Enter coords of top left pt:";
        cin >> xmin >> ymin;
        cout << "Enter coords of bottom right pt:";
        cin >> xmax >> ymax;
    }
    void draw() {
        line(xmin, ymin, xmax, ymin);
        line(xmax, ymin, xmax, ymax);
        line(xmax, ymax, xmin, ymax);
        line(xmin, ymax, xmin, ymin);
    }
};

class Line {
   public:
    int x1, x2, y1, y2;
    int code1, code2;
    double slope;
    void create() {
        cout << "Enter coords x1,y1:";
        cin >> x1 >> y1;
        cout << "Enter coords x2,y2:";
        cin >> x2 >> y2;
        if (x1 == x2) {
            slope = 1;
        } else {
            slope = (y2 - y1) / (x2 - x1);
        }
    }
    void draw() { line(x1, y1, x2, y2); }
    void resetCode(window w1) {
        code1 = w1.getcode(x1, y1);
        code2 = w1.getcode(x2, y2);
    }
};

void clip() {
    window w1;
    w1.create();
    // Line l1;
    // l1.create();

    double x1, x2, y1, y2;
    int code1, code2, outcode;
    double slope;

    cout << "Enter coords x1,y1:";
    cin >> x1 >> y1;
    cout << "Enter coords x2,y2:";
    cin >> x2 >> y2;
    if (x1 == x2) {
        slope = 1;
    } else {
        slope = (y2 - y1) / (x2 - x1);
    }

    setcolor(RED);
    outtext("Before Cliping");
    w1.draw();
    // l1.draw();
    line(x1, y1, x2, y2);

    code1 = w1.getcode(x1, y1);
    code2 = w1.getcode(x2, y2);

    delay(3000);
    cleardevice();

    setcolor(GREEN);
    outtext("After Cliping");
    bool accept = false;
    double y, x;
    while (true) {
        // l1.resetCode(w1);
        cout<<code1<<code2<<" ";
        line(x1, y1, x2, y2);
        // l1.draw();
        if (code1 == 0 && code2 == 0) {
            accept = true;
            break;
        } else if ((code1 & code2) > 0) {
            accept = false;
            break;
        } else {
            if (code1 == 0) {
                outcode = code2;
            } else {
                outcode = code1;
            }

            if (outcode & LEFT) {
                y = (slope * (w1.xmin - x1) )+ y1;
                x = w1.xmin;
            } else if (outcode & RIGHT) {
                y = (slope * (w1.xmax - x1)) + y1;
                x = w1.xmax;
            } else if (outcode & TOP) {
                x = ((w1.ymin - y1) / slope )+ x1;
                y = w1.ymin;
            } else if (outcode & BOTTOM) {
                x = ((w1.ymax - y1) / slope) + x1;
                y = w1.ymax;
            }

            if (code1 == outcode) {
                x1 = x;
                y1 = y;
                code1 = w1.getcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = w1.getcode(x2, y2);
            }
        }
    }
    cleardevice();
    w1.draw();

    if (accept) {
        line(x1, y1, x2, y2);
        // draw();
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    clip();

    getch();
    closegraph();
    return 0;
}

/*
50 50 250 150
40 30 250 160
*/