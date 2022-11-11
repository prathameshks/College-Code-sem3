#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;


void koch_curve(int x1,int y1,int x2,int y2,int iter){
    if (iter==0){
    line(x1,y1,x2,y2);
    return;
    }else{
    float p1x,p1y,p2x,p2y,ix,iy;
//delay(10);
    p1x = (2*x1+x2)/3;
    p2x = (x1+2*x2)/3;
    p1y = (2*y1+y2)/3;
    p2y = (y1+2*y2)/3;
    ix=(int)(0.5*(x1+x2)+sqrt(3)*(y1-y2)/6);
    iy=(int)(0.5*(y1+y2)+sqrt(3)*(x2-x1)/6);
    
    //next calls
    koch_curve(x1,y1,p1x,p1y,iter-1);
    koch_curve(p1x,p1y,ix,iy,iter-1);
    koch_curve(ix,iy,p2x,p2y,iter-1);
    koch_curve(p2x,p2y,x2,y2,iter-1);
    }
}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    //triangle 
    int iterations=5;
    //cin>>iterations;
    koch_curve(250,50,120,125,iterations);
    koch_curve(120,125,250,200,iterations);
    koch_curve(250,200,250,50,iterations);
    
    getch();
    closegraph();
    return 0;
}
