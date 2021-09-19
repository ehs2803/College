#include<stdio.h>
#include "deque_link.h"

void Inint_deque_link(deque_link* Dptr) {
	Dptr->count = 0;
	Dptr->head = NULL;
	Dptr->tail = NULL;
}

int Count_deque_link(deque_link* Dptr) {
	return Dptr->count;
}

void DqAddFront(deque_link* Dptr, int item) {
	Nptr_deque p= malloc(sizeof(node_deque));
	p->data = item;
	if (Dptr->head == NULL && Dptr->tail == NULL) {
		p->next = NULL;
		p->prev = NULL;
		Dptr->head = p;
		Dptr->tail = p;
	}
	else {
		p->next = Dptr->head;
		Dptr->head = p;
		p->prev = NULL;
    }
	Dptr->count++;
}

void DqAddTail(deque_link* Dptr, int item) {
	Nptr_deque p = malloc(sizeof(node_deque));
	p->data = item;
	if (Dptr->head == NULL && Dptr->tail == NULL) {
		p->next = NULL;
		p->prev = NULL;
		Dptr->head = p;
		Dptr->tail = p;
	}
	else {
		p->prev = Dptr->tail;
		Dptr->tail = p;
		p->next = NULL;
	}
	Dptr->count++;
}

int DqRemoveFront(deque_link* Dptr) {
	if (Dptr->head == NULL && Dptr->tail == NULL) {
		printf("덱이 비어있습니다.\n");
	}
	else if (Dptr->head == Dptr->tail) {
		int rtemp = Dptr->head->data;
		free(Dptr->head);
		Dptr->head = NULL;
		Dptr->tail = NULL;
		Dptr->count--;
		return rtemp;
	}
	else {
		Nptr_deque temp = Dptr->head;
		int rtemp = Dptr->head->data;
		Dptr->head = temp->next;
		Dptr->head->prev = NULL;
		free(temp);
		Dptr->count--;
		return rtemp;
	}
}

int DqRemoveTail(deque_link* Dptr) {
	if (Dptr->head == NULL && Dptr->tail == NULL) {
		printf("덱이 비어있습니다.\n");
	}
	else if (Dptr->head == Dptr->tail) {
		int rtemp = Dptr->head->data;
		free(Dptr->head);
		Dptr->head = NULL;
		Dptr->tail = NULL;
		Dptr->count--;
		return rtemp;
	}
	else {
		Nptr_deque temp = Dptr->tail;
		int rtemp = Dptr->tail->data;
		Dptr->tail = temp->prev;
		Dptr->tail->next = NULL;
		free(temp);
		Dptr->count--;
		return rtemp;
	}
}

bool IsEmpty_deque_link(deque_link* Dptr) {
	if (Dptr->head == NULL && Dptr->tail == NULL)return true;
	else return false;
}

void getFront_deque_link(deque_link* Dptr, int* item) {
	if (Dptr->head == NULL && Dptr->tail == NULL) {
		printf("덱이 비어있습니다.\n");
	}
	else {
		item = Dptr->head->data;
	}
}

void getTail_deque_link(deque_link* Dptr, int* item) {
	if (Dptr->head == NULL && Dptr->tail == NULL) {
		printf("덱이 비어있습니다.\n");
	}
	else {
		item = Dptr->tail->data;
	}
}

void FreeDeque_link(deque_link* Dptr) {
	while (!IsEmpty_deque_link(Dptr)) {
		DqRemoveFront(Dptr);
	}
}
//20200708-3