#include<stdio.h>
#include<stdlib.h>
#include "queue_link.h"

void Inint_queue_link(Queue_link* Qptr) {
	Qptr->count = 0;
	Qptr->Rear = NULL;
}

void Add_link(Queue_link* Qptr, int item) {
	Nptr_queue p = malloc(sizeof(node_queue));
	p->Data = item;
	if (!IsEmpty_queue_link(Qptr)) {
		p->Next = Qptr->Rear->Next;
		Qptr->Rear->Next = p;
		Qptr->Rear = p;
		Qptr->count++;
	}
	else {
		p->Next = p;
		Qptr->Rear = p;
		Qptr->count++;
	}
}

int Remove_link(Queue_link* Qptr) {
	Nptr_queue Front = Qptr->Rear->Next;
	int num = Front->Data;
	if (Getsize_link(Qptr) >= 2) {
		Qptr->Rear->Next = Front->Next;
		free(Front);
		Qptr->count--;
		return num;
	}
	else if (Getsize_link(Qptr) == 1) {
		Qptr->Rear = NULL;
		free(Front);
		Qptr->count--;
		return num;
	}
	else {
		printf("큐가 비어있습니다.\n");
	}
}

bool IsEmpty_queue_link(Queue_link* Qptr) {
	if (Qptr->count == 0)return true;
	else return false;
}

int Getsize_link(Queue_link* Qptr) {
	return Qptr->count;
}

void getFront_link(Queue_link* Qptr, int* item) {
	if (IsEmpty_queue_link(Qptr)) {
		printf("큐가 비었습니다.\n");
	}
	else {
		item = Qptr->Rear->Next->Data;
	}
}

void FreeQueue_link(Queue_link* Qptr) {
	while (!IsEmpty_queue_link(Qptr)) {
		Remove_link(Qptr);
	}
}
//20200706-4