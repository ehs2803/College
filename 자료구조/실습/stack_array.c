#include<stdio.h>
#include<stdbool.h>
#include "stack_array.h"

void Inint_stack_array(stackType* Sptr) {
	Sptr->Top = -1;
}

int Count_stack_array(stackType* Sptr) {
	return Sptr->Top + 1;
}

void Push_array(stackType* Sptr, int item) {
	if (IsFull_stack_array(Sptr)) {
		printf("������ �� á���ϴ�.\n");
	}
	else {
		Sptr->Top++;
		Sptr->Stack[Sptr->Top] = item;
	}
}

int Pop_array(stackType* Sptr) {
	int temp;
	if (IsEmpty_stack_array(Sptr)) {
		printf("������ ������ϴ�.\n");
	}
	else {
		temp = Sptr->Stack[Sptr->Top];
		Sptr->Top--;
		return temp;
	}
}

bool IsEmpty_stack_array(stackType* Sptr) {
	if (Sptr->Top == -1)return true;
	else return false;
}

bool IsFull_stack_array(stackType* Sptr) {
	if (Sptr->Top == MAX-1)return true;
	else return false;
}

void getTop_array(stackType* Sptr, int* item) {
	if (IsEmpty_stack_array(Sptr)) {
		printf("������ ������ϴ�.\n");
	}
	else{
		item = Sptr->Stack[Sptr->Top];
	}
}
//20200706-4