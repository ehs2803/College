#include<stdio.h>
#include "queue_array.h"

void Inint_queue_array(Queue_array* Qptr) {
	Qptr->count = 0;
	Qptr->Front = 0;
	Qptr->Rear = -1;
}

void Add_array(Queue_array* Qptr, int item) {
	if (Qptr->count == MAX) {
		printf("큐가 꽉 찼습니다.\n");
	}
	else {
		Qptr->Rear = (Qptr->Rear + 1) % MAX;
		Qptr->Queue[Qptr->Rear] = item;
		Qptr->count++;
	}
}

int Remove_array(Queue_array* Qptr) {
	if (Qptr->count == 0) {
		printf("큐가 비었습니다.\n");
	}
	else {
		Qptr->Front = (Qptr->Front + 1) % MAX;
		Qptr->count--;
	}
}

bool IsEmpty_queue_array(Queue_array* Qptr) {
	if (Qptr->count == 0)return true;
	else return false;
}

int Getsize_array(Queue_array* Qptr) {
	return Qptr->count;
}

void getFront_array(Queue_array* Qptr, int* item) {
	if (IsEmpty_queue_array(Qptr)) {
		printf("큐가 비었습니다.\n");
	}
	else {
		item = Qptr->Queue[Qptr->Front];
	}
}
//20200706-4