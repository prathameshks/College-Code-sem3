#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void man(int sx, int sy, int step)
{
	// body
	line(sx, sy, sx, sy + 45);
	rectangle(sx - 3, sy + 10, sx + 3, sy + 45);

	// head
	circle(sx, sy - 10, 10);

	// hand left
	if (step == 1)
	{
		line(sx, sy + 10, sx - 15, sy + 30);
	}
	else if (step == 2)
	{

		line(sx, sy + 10, sx + 10, sy + 30);
	}

	// hand right
	line(sx, sy + 10, sx + 15, sy + 25);

	// umbrella
	line(sx + 15, sy + 25, sx + 15, sy - 20);
	arc(sx + 13, sy + 25, 0, 180, 2);
	arc(sx + 15, sy - 20, 180, 0, 30);
	line(sx - 15, sy - 20, sx + 45, sy - 20);

	if (step == 1)
	{

		// leg left
		line(sx, sy + 45, sx - 5, sy + 75);

		// leg right
		line(sx, sy + 45, sx + 10, sy + 75);
	}
	else if (step == 2)
	{

		// leg left
		line(sx, sy + 45, sx - 10, sy + 75);

		// leg right
		line(sx, sy + 45, sx + 5, sy + 75);
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

	// man(300,100,2);
	int ground[4] = {20, 400, 600, 400};

	line(ground[0], ground[1], ground[2], ground[3]); // ground
	int step = 1;
	for (int i = ground[0]; i < ground[2]; i += 10)
	{
		line(ground[0], ground[1], ground[2], ground[3]); // ground

		man(i, ground[1] - 75, step);
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

	// getch();
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