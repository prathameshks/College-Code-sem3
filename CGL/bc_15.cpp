#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;


void drawCircle(int xc, int yc, int x, int y)
{
 putpixel(xc+x, yc+y, RED);
 putpixel(xc-x, yc+y, RED);
 putpixel(xc+x, yc-y, RED);
 putpixel(xc-x, yc-y, RED);
 putpixel(xc+y, yc+x, RED);
 putpixel(xc-y, yc+x, RED);
 putpixel(xc+y, yc-x, RED);
 putpixel(xc-y, yc-x, RED);
}


void circleBres(int xc, int yc, int r)
{
 int x = 0, y = r;
 int d = 3 - 2 * r;
 drawCircle(xc, yc, x, y);
 while (y >= x)
 {
  x++;

  if (d > 0)
  {
   y--;
   d = d + 4 * (x - y) + 10;
  }
  else
   d = d + 4 * x + 6;
  drawCircle(xc, yc, x, y);
  delay(50);
 }
}

void DDALine(int x0, int y0, int x1, int y1)
{
 
    // Calculate dx and dy
    int dx = x1 - x0;
    int dy = y1 - y0;
 
    int step;
 
    // If dx > dy we will take step as dx
    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
 
    // Calculate x-increment and y-increment for each step
    float x_incr = (float)dx / step;
    float y_incr = (float)dy / step;
 
    // Take the initial points as x and y
    float x = x0;
    float y = y0;
 
    for (int i = 0; i < step; i++) {
 
        putpixel(round(x), round(y), RED);
        x += x_incr;
        y += y_incr;
        // delay(10);
    }
}




void pattern1(int x,int y,int r){
        int x1,y1,x2,y2,x3,y3,r1;
        x1 = x;
        y1 = y-r;
        x2 = x-(0.866 * r);
        x3 = x+(0.866 * r);
        y2=y+r/2;
        y3=y+r/2;
        r1 = r/2;
        
        circleBres(x,y,r);
        
        DDALine(x1,y1,x2,y2);
        
        DDALine(x2,y2,x3,y3);
        
        DDALine(x3,y3,x1,y1);

        circleBres(x,y,r1);
}

void pattern2(int x1,int y1,int side){}

// Driver code
int main()
{
        int gd = DETECT, gm;
        initgraph(&gd, &gm,NULL); // initialize graph
        /*
        int x,y,r;
        cout<<"Enter coordinates of circle:";
        cin>>x>>y;

        cout<<"Enter radius of circle:";
        cin>>r;
        
        pattern1(x,y,r);
        */
        

        getch();
 return 0;
}

