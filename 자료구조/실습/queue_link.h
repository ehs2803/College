#ifndef __QUEUE_LINK_H__
#define __QUEUE_LINK_H__
#include<stdbool.h>

typedef struct nodeRecord_queue {
	int Data;
	struct nodeRecord_queue* Next;
}node_queue;
typedef node_queue* Nptr_queue;

typedef struct {
	int count;
	Nptr_queue Rear;
}Queue_link;

void Inint_queue_link(Queue_link* Qptr);

void Add_link(Queue_link* Qptr, int item);

int Remove_link(Queue_link* Qptr);

bool IsEmpty_queue_link(Queue_link* Qptr);

int Getsize_link(Queue_link* Qptr);

void getFront_link(Queue_link* Qptr, int* item);

void FreeQueue_link(Queue_link* Qptr);

#endif
//20200706-4