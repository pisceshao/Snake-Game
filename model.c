#include <stdio.h>
#include <stdlib.h>
#include "model.h"

void createList(node **head, node **tail)
{
	
	*head  = (node*)malloc(sizeof(node));	
	*tail  = (node*)malloc(sizeof(node));	
	node *newnode = (node*)malloc(sizeof(node));
	newnode->next = *head;		newnode->back = *tail;
	newnode->dir = 'R';		newnode->dx = newnode->dy = 2;
	(*head)->next = newnode;		(*head)->back = NULL;
	(*tail)->back = newnode;		(*tail)->next = NULL;
}

void addToHead(node *head)
{
	node *newnode = (node*)malloc(sizeof(node));
	node *cur = head->next;
	newnode->back = head;		newnode->next = cur;
	newnode->dir = cur->dir;
	newnode->dx = cur->dx;		newnode->dy = cur->dy;
	switch(cur->dir)
	{
		case 'R': newnode->dy ++; break;
		case 'L': newnode->dy --; break;
		case 'W': newnode->dx --; break;
		case 'D': newnode->dx ++; break;
	}
	cur->back = newnode;		head->next = newnode;	
}

void delToTail(node *tail)
{
	node *newnode = tail->back;
	tail->back = tail->back->back; tail->next = NULL;
	free(newnode);
}
