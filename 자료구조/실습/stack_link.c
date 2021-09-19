#include<stdio.h>
#include "stack_link.h"

void Inint_stack_link(node_stack** Top) {
	*Top == NULL;
}

void Push_link(node_stack** Top, int item) {
	Nptr_stack temp = malloc(sizeof(node_stack));
	temp->Data = item;
	temp->Next = *Top;
	*Top = temp;
}

int Pop_link(node_stack** Top) {
	if (IsEmpty_stack_link(*Top)) {
		printf("스택이 비었습니다.\n");
	}
	else {
		Nptr_stack temp = *Top;
		int item = temp->Data;
		*Top = (*Top)->Next;
		free(temp);
		return item;
	}
}

bool IsEmpty_stack_link(node_stack** Top) {
	if (*Top == NULL)return true;
	else return false;
}

void getTop_link(node_stack** Top, int* item) {
	if (IsEmpty_stack_link(*Top)) {
		printf("스택이 비었습니다.\n");
	}
	else {
		item = (*Top)->Data;
	}
}

void FreeStack_link(node_stack** Top) {
	Nptr_stack temp = *Top;
	while (temp != NULL) {
		*Top = (*Top)->Next;
		free(temp);
		temp = *Top;
	}
}
//20200706-4