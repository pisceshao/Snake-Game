#ifndef __MODE_H
#define __MODE_H

typedef struct _node{
	char dir;
	int dx, dy;
	struct _node * next;
	struct _node * back;
}node;

void createList();
void addToHead();
void delToTail();
void traverseList();

#endif


