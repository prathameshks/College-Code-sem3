/*
a) Write C++ program to draw 2-D object and perform following basic
transformations, Scaling b) Translation c) Rotation. Apply the concept of
operator overloading.*/


#include <graphics.h>
#include <math.h>

#include <iostream>

using namespace std;

class poly {
   public:
    double coords[10][3] = {0};
    int n;
    double ans[10][3] = {0};

    void set() {
        cout << "Enter vertex cnt:";
        cin >> n;
        cout << "Enter vertex :";
        for (int i = 0; i < n; i++) {
            cin >> coords[i][0] >> coords[i][1];
            coords[i][2] = 1;
        }
    }

    void operator*(double mat[3][3]) {
        double val;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                val = 0;
                for (int k = 0; k < 3; k++) {
                    val += (coords[i][k] * mat[k][j]);
                }
                ans[i][j] = val;
            }
        }
    }

    void draw() {
        for (int i = 0; i < n; i++) {
            cout << coords[i][0] << " " << coords[i][1] << endl;
        }
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            line(coords[i][0], coords[i][1], coords[next][0], coords[next][1]);
        }
    }
    void draw_trans() {
        for (int i = 0; i < n; i++) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            line(ans[i][0], ans[i][1], ans[next][0], ans[next][1]);
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    double translation[3][3] = {{1, 0, 0}, {0, 1, 0}, {50, 50, 1}};
    double scaling[3][3] = {{2, 0, 0}, {0, 3, 0}, {0, 0, 1}};
    double rotation[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 1}};

    int theta;
    cin >> theta;

    double rad = 3.14 * theta / 180;

    rotation[0][0] = cos(rad);
    rotation[1][1] = cos(rad);

    rotation[0][1] = -sin(rad);
    rotation[1][0] = sin(rad);

    poly p;
    p.set();
    p.draw();

    // p* translation;
    // p* scaling;
    p* rotation;

    setcolor(RED);
    p.draw_trans();

    getch();
    closegraph();
    return 0;
}

/*
10
3 100 100 100 150 150 150

*/