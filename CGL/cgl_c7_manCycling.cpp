#include <iostream>
#include <graphics.h>
#include <math.h>
// #define PI acos(-1)
using namespace std;

void linerotate(int x1, int y1, int x2, int y2, float angle)
{
	float s = sin(angle);
	float c = cos(angle);

	// midpoint of line
	float mx, my;
	mx = (x1 + x2) / 2;
	my = (y1 + y2) / 2;

	// translate point back to origin:
	x1 -= mx;
	y1 -= my;
	x2 -= mx;
	y2 -= my;

	// rotate point
	float xnew1 = x1 * c - y1 * s;
	float ynew1 = x1 * s + y1 * c;
	float xnew2 = x2 * c - y2 * s;
	float ynew2 = x2 * s + y2 * c;

	// translate point back:
	x1 = xnew1 + mx;
	y1 = ynew1 + my;
	x2 = xnew2 + mx;
	y2 = ynew2 + my;

	line(x1, y1, x2, y2);
}

void tyre(int cx, int cy, int rad, bool next = false)
{
	// ring
	circle(cx, cy, rad);
	int rad2 = (rad / 1.414);
	// forks
	if (next)
	{
		linerotate(cx - rad, cy, cx + rad, cy, 0.524);
		linerotate(cx, cy - rad, cx, cy + rad, 0.524);
		linerotate(cx - rad2, cy - rad2, cx + rad2, cy + rad2, 0.524);
		linerotate(cx - rad2, cy + rad2, cx + rad2, cy - rad2, 0.524);
	}
	else
	{
		line(cx - rad, cy, cx + rad, cy);
		line(cx, cy - rad, cx, cy + rad);
		line(cx - rad2, cy - rad2, cx + rad2, cy + rad2);
		line(cx - rad2, cy + rad2, cx + rad2, cy - rad2);
	}
}
void manwithcycle(int sx, int sy, int step)
{
	// cycle
	// line(sx + 30, sy - 30, sx + 80, sy - 30);

	int i = 0;
	/*
	50 = sx+30
	75 = sx+55
	80 = sx+60
	100 = sx+80
	150 = sx+130

sy = 435
	405 = sy-30
	375 = sy-60
	345 = sy-90
	*/
	line(sx + 30, sy - 30, sx + 80, sy - 30);
	line(sx + 55, sy - 60, sx + 105, sy - 60);

	line(sx + 30, sy - 30, sx + 55, sy - 60);
	line(sx + 80, sy - 30, sx + 105, sy - 60);

	line(sx + 55, sy - 60, sx + 105, sy - 60);

// line(150 + i, 405, 100 + i, 345);
	line(sx + 130, sy - 30, sx + 80, sy - 90);

	// line(sx + 50, sy - 65, sx + 60, sy - 65);
	// line(sx + 60, sy - 90, sx + 80, sy - 90);
	// tyres
	if (step == 1)
	{
		tyre(sx + 30, sy - 30, 25);
		tyre(sx + 130, sy - 30, 25);
	}
	else
	{
		tyre(sx + 30, sy - 30, 25, true);
		tyre(sx + 130, sy - 30, 25, true);
	}
}

void rain(int x, int y, int intensity)
{
	int i, rx, ry;
	for (i = 0; i < intensity; i++)
	{
		rx = rand() % x;
		ry = rand() % y;
		if (ry < y - 4 and rx > 2)
		{
			line(rx, ry, rx - 1, ry + 4);
		}
	}
}

int main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, NULL);
	int step=0;
	for (int i = 0; i < 400; i+=10)
	{
		manwithcycle(10+i, 200, step);
		if (step == 1)
			step = 0;
		else
			step = 1;

		delay(100);
		cleardevice();
		
	}
	
	// manwithcycle(100, 200, 1);
	// manwithcycle(300, 200, 0);
	/*
		// man(300,100,2);
		int ground[4] = {20, 400, 600, 400};

		line(ground[0], ground[1], ground[2], ground[3]); // ground
		int step = 1;
		for (int i = ground[0]; i < ground[2]; i += 10)
		{
			line(ground[0], ground[1], ground[2], ground[3]); // ground

			// man(i, ground[1] - 75, step);
			if (step == 1)
			{
				step = 2;
			}
			else
			{
				step = 1;
			}
			rain(ground[2],ground[3],100);
			delay(350);
			cleardevice();
		}
	*/
	getch();
	closegraph();
	return 0;
}

// for (int j = 325; j < 400; j += 10)
// {
// 	man(500, j, 1);
// 	line(ground[0], ground[2], ground[2], ground[3]); // ground

// 	outtextxy(550, j - 50, " HELP ME.");
// 	delay(150);
// 	cleardevice();
// }