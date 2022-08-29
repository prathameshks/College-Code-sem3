#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{
	int gdriver = DETECT, gmode; // get driver from detect automatically and store to variable gdriver
	cout<<"Ploating"<<endl;
	initgraph(&gdriver, &gmode, NULL); // init the graph which is window where we can draw the shapes
	rectangle(100,100,200,300);
	setcolor(RED);
	circle(125,125,40);
	setcolor(WHITE);
	line(125,165,125,250);

	delay(5000); // delay to seee the output time in milli sec
	closegraph(); // to close the window but it will close window asap it executes so we will not be able to se it for that delay is to be added
	return 0;
}
