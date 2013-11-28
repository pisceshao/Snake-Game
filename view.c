#include "view.h"

void drawFood(int dx, int dy)
{
	move(dx, dy);
	printw("@");
	refresh();
}

void drawSnake(int dx, int dy)
{
	move(dx, dy);
	printw("#");
	refresh();
}

void drawSpace(int dx, int dy)
{
	move(dx, dy);
	printw(" ");
	refresh();
}
