#include<iostream>
#include<graphics.h>
#define MAX_SIZE 10

using namespace std;

int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    getch();
    closegraph();
    return 0;
}