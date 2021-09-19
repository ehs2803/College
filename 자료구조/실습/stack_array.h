#ifndef __STACK_ARRAY_H__
#define __STACK_ARRAY_H__
#include<stdbool.h>
#define MAX 100

typedef struct {
	int Top;
	int Stack[MAX];
}stackType;

void Inint_stack_array(stackType* Sptr);

int Count_stack_array(stackType* Sptr);

void Push_array(stackType* Sptr, int item);

int Pop_array(stackType* Sptr);

bool IsEmpty_stack_array(stackType* Sptr);

bool IsFull_stack_array(stackType* Sptr);

void getTop_array(stackType* Sptr, int* item);

#endif
//20200706-4