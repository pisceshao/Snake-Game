#include "controller.h"
#include "view.h"
#include "model.h"
#include <stdlib.h>

int food_x, food_y;
int dir_x, dir_y;
node *head, *tail;

void initGame()
{
	WINDOW *w = subwin(stdscr, 10, 20, 1, 1);
	box(w, ACS_VLINE, ACS_HLINE);
	refresh();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	srand(time(NULL));
	food_x = rand()%8+2; food_y = rand()%8+2;
}


int main(int argc, const char *argv[])
{
	int i;
	initscr();
	initGame();
	createList(&head, &tail);
	drawSnake(head->next->dx, head->next->dy);
	getch();
	for(i = 0; i < 10; i ++)
	{
		drawFood(food_x, food_y);
		addToHead(head);
		drawSnake(head->next->dx, head->next->dy);
		drawSpace(tail->back->dx, tail->back->dy);
		delToTail(tail);
		calcTime(3);
	}
	getch();
	endwin();

	return 0;
}
