#include<iostream>
#include<graphics.h>
#include <math.h>
using namespace std;

void man(int sx,int sy,int step){
//body
	line(sx,sy,sx,sy+60);
	
	//head
	circle(sx,sy-10,10);
	
	//hand left
	if(step==1){
	line(sx,sy+10,sx-10,sy+25);
	}else if(step==2){
		
	line(sx,sy+10,sx+7,sy+25);
	}
	
	//hand right
	line(sx,sy+10,sx+15,sy+25);
	
	//umbrella
	line(sx+15,sy+25,sx+15,sy-20);
	arc(sx+17,sy+25,0,180,2);
	arc(sx+15,sy-20,180,0,30);
	line(sx-15,sy-20,sx+45,sy-20);
		
		if(step==1){
		
	//leg left
	line(sx,sy+60,sx-5,sy+75);
	
	//leg right
	line(sx,sy+60,sx+10,sy+75);
	}else if(step==2){
		
	//leg left
	line(sx,sy+60,sx-10,sy+75);
	
	//leg right
	line(sx,sy+60,sx+5,sy+75);
	}
	
	
}


int main()
{
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,NULL);
	
	//man(300,100,2);
	line(100,400,500,400);//ground
	int step=1;
	for (int i=100;i<500;i+=10){
	line(100,400,500,400);//ground
		man(i,400-75,step);	
		if(step==1){
		step = 2;
		}else{
		step=1;
		}	
		delay(200);
		cleardevice();
	}
	
	for(int j=325;j<400;j+=10){
	man(500,j,1);
	
	line(100,400,500,400);//ground
	outtextxy(550,j-50," HELP ME.");
		delay(150);
		cleardevice();
	}
	
	//getch();
	closegraph();
	return 0;
}
