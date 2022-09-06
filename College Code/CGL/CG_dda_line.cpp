#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

void dda_line(int x1,int y1,int x2,int y2){
    float dx = x2-x1;
    float dy = y2-y1;
    
    float step;
    
    float x = x1;
    float y = y1;
    //step = abs(dx)>abs(dy) ? abs(dx) : abs(dy);
    if (abs(dx)>abs(dy)){
        step =  abs(dx);
    }else{
        step = abs(dy);
    }
    
    float xinc,yinc;
    xinc = dx/step;
    yinc = dy/step;
    
    for (int i = 0;i<=step;i++){
        putpixel(round(x),round(y),RED);
        x+=xinc;
        y+=yinc;
    }
    
    
}


int main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, NULL);
	cout<<"Running init"<<endl;
	// delay(2000);
	
	int x1,y1,x2,y2;
	cout<<"Enter coords of start :";
	cin>>x1>>y1;
    cout<<"Enter coords of end :";
	cin>>x2>>y2;
	
	dda_line(x1,y1,x2,y2);
	/*
    dda_line(100,20,30,400);
    line(100,20,30,400);
	delay(5000); 
	*/
	// int out;
	// cin>>out;
	
    getch();
    
	closegraph(); 
	return 0;
}
