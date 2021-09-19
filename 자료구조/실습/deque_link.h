#ifndef __DEQUE_LINK_H__
#define __DEQUE_LINK_H__
#include<stdbool.h>

typedef struct nodeDeque {
	int data;
	struct nodeDeque* next;
	struct nodeDeque* prev;
}node_deque;
typedef node_deque* Nptr_deque;

typedef struct{
	Nptr_deque head, tail;
	int count;
} deque_link;

void Inint_deque_link(deque_link* Dptr);

int Count_deque_link(deque_link* Dptr);

void DqAddFront(deque_link* Dptr, int item);

void DqAddTail(deque_link* Dptr, int item);

int DqRemoveFront(deque_link* Dptr);

int DqRemoveTail(deque_link* Dptr);

bool IsEmpty_deque_link(deque_link* Dptr);

void getFront_deque_link(deque_link* Dptr, int* item);

void getTail_deque_link(deque_link* Dptr, int* item);

void FreeDeque_link(deque_link* Dptr);

#endif
//20200708-3