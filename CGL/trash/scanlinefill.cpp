#include <graphics.h>

#include <algorithm>
#include <iostream>
#define max 21

using namespace std;

class polygaon {
   public:
    int vertex[max][2];
    int n;

    void set_poly() {
        cout << "Enter number of vertices(max 20):";
        cin >> n;
        if (n > 20) n = (max - 1);

        for (int i = 0; i < n; i++) {
            cout << "Enter quardinates of vertex " << i + 1 << " :";
            cin >> vertex[i][0] >> vertex[i][1];
        }
        vertex[n][0] = vertex[0][0];
        vertex[n][1] = vertex[0][1];
    }

    void display() {
        for (int i = 0; i < n; i++) {
            line(vertex[i][0], vertex[i][1], vertex[i + 1][0],
                 vertex[i + 1][1]);
        }
    }
};

class poly_fill : public polygaon {
    int ymin, ymax;
    int dx, dy;

    void set_range() {
        ymin = ymax = vertex[0][1];
        for (int i = 0; i < n; i++) {
            if (vertex[i][1] > ymax) ymax = vertex[i][1];
            if (vertex[i][1] < ymin) ymin = vertex[i][1];
        }
    }

    void setslope() {
        for (int i = 0; i < n; i++) {
            dx = vertex[i + 1][0] - vertex[i][0];
            dy = vertex[i + 1][1] - vertex[i][1];

            if (dx == 0)
                slope[i] = 1;
            else if (dy == 0)
                slope[i] = 0;
            else
                slope[i] = float(dx / dy);
        }
    }

   public:
    int intersects[max];
    int k;
    float slope[max];

    void fill() {
        set_range();
        setslope();
        for (int y = ymin; y < ymax; y++) {
            k = 0;
            for (int i = 0; i < n; i++) {
                if ((vertex[i][1] <= y and y <= vertex[i + 1][1]) ||
                    (vertex[i][1] >= y and y >= vertex[i + 1][1])) {
                    intersects[k] =
                        (int)(vertex[i][0] + slope[i] * (y - vertex[i][1]));
                    k++;
                }

                // if ((vertex[i][1] <= ycord) && (vertex[i + 1][1] > ycord)
                //     || ((vertex[i][1] > ycord) && (vertex[i + 1][1] <=
                //     ycord))) {
                //         intersects[k] =
                //             (int)(vertex[i][0] +
                //                   slope[i] * (ycord - vertex[i][1]));
                //         k++;
            }
            // }
            sort(&intersects[0], &intersects[k]);
            for (int p = 0; p < k; p++) {
                cout << intersects[p] << " ";
            }
            cout << endl;
            int j = 0;
            while (j < k) {
                line(intersects[j], y, intersects[j + 1], y);
                j += 2;
            }
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    poly_fill p1;
    p1.set_poly();

    p1.display();

    p1.fill();
    getch();
    closegraph();
    return 0;
}

/*
6
10 20
100 30
150 100
90 200
40 150
20 200

*/