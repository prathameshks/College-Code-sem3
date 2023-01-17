#include <graphics.h>
#include <math.h>

#include <iostream>

using namespace std;

void ddacircle1(int x, int y, int r) {
    double t,val;

    for (int i = (-r); i <= r; i++) {
        t = (r * r - i * i);
        val = sqrt(t)+0.5;
        putpixel(x + i, y + val, RED);
        putpixel(x + i, y - val, RED);
    }
}

void ddacircle2(int x, int y, int r) {
    double t,val;

    for (int i = (-r); i <= r; i++) {
        t = (r * r - i * i);
        val = sqrt(t)+0.5;
        putpixel(x + val, y + i, GREEN);
        putpixel(x - val, y + i, GREEN);
    }
}






int main() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    cout << "DDA CIRCLE X" << endl;
    ddacircle1(100, 100, 50);
    cout << "DDA CIRCLE Y" << endl;
    ddacircle2(100, 100, 50);

    getch();
    closegraph();
    return 0;
}