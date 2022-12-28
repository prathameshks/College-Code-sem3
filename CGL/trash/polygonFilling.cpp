#include <graphics.h>

#include <iostream>
#define max 10
using namespace std;

typedef struct edge {
    int x1, y1, x2, y2, flag;
} edge;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    edge edge_list[max];
    double slope[max], x_intrcpt[max], inter_x[max], temp;
    int x[max + 1], y[max + 1];
    int ymax = 0, ymin = 1000, dx, dy, ycord;

    int n;
    cout << "Enter number of vertices(max " << max << ") :";
    cin >> n;

    if (n > max) n = max;
    // n = (n>max) ? max : n;

    for (int i = 0; i < n; i++) {
        cout << "Enter vertex of point " << i + 1 << ":";
        cin >> x[i] >> y[i];
        if (y[i] > ymax) ymax = y[i];
        if (y[i] < ymin) ymin = y[i];
    }

    x[max] = x[0];
    y[max] = y[0];

    for (int i = 0; i < n; i++) {
        if (y[i] < y[i + 1]) {
            edge_list[i].x1 = x[i + 1];
            edge_list[i].y1 = y[i + 1];
            edge_list[i].x2 = x[i];
            edge_list[i].y2 = y[i];
        } else {
            edge_list[i].x1 = x[i];
            edge_list[i].y1 = y[i];
            edge_list[i].x2 = x[i + 1];
            edge_list[i].y2 = y[i + 1];
        }
    }

    // display edges
    for (int i = 0; i < n; i++) {
        cout << "(" << edge_list[i].x1 << "," << edge_list[i].y1 << "),("
             << edge_list[i].x2 << "," << edge_list[i].y2 << ")" << endl;
        line(edge_list[i].x1, edge_list[i].y1, edge_list[i].x2,
             edge_list[i].y2);
    }

    // calculating 1/slope of each edge
    for (int i = 0; i < n; i++) {
        dx = edge_list[i].x2 - edge_list[i].x1;
        dy = edge_list[i].y2 - edge_list[i].y1;
        if (dy == 0) {
            slope[i] = 0;
        } else {
            slope[i] = dx / dy;
        }
        inter_x[i] = edge_list[i].x1;
    }

    ycord = ymin;
    while (ymax > ycord++) {
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (edge_list[i].y1 >= ycord && edge_list[i].y2 <= ycord) {
                edge_list[i].flag = 1;
            } else {
                edge_list[i].flag = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (edge_list[i].flag) {
                if (ycord != edge_list[i].y1) {
                    x_intrcpt[j] = inter_x[i] - slope[i];
                    inter_x[i] = x_intrcpt[j];
                    j++;
                }
            }
        }

        for (int p = j - 1; p >= 0; p--) {
            for (int q = 0; q < p; q++) {
                if (x_intrcpt[q] > x_intrcpt[q + 1]) {
                    temp = x_intrcpt[q];
                    x_intrcpt[q] = x_intrcpt[q + 1];
                    x_intrcpt[q + 1] = temp;
                }
            }
        }

        for (int i = 0; i < j; i = i + 2) {
            line((int)x_intrcpt[i], ycord, (int)x_intrcpt[i + 1], ycord);
        }

        delay(50);
    }

    getch();
    closegraph();
    return 0;
}

/*
5 80 20 100 80 150 60 130 200 40 250

6
50 50 100 50 120 120 80 80 50 120 40 60



                if (edge_list[i].y2 == ycord) {
                    if (edge_list[i].y1 > ycord &&
                        edge_list[i + 1].y2 < ycord) {
                        continue;
                    }
                }
                if (edge_list[i].y1 == ycord) {
                    if (edge_list[i].y2 < ycord &&
                        edge_list[i + 1].y1 > ycord) {
                        continue;
                    }
                }

*/