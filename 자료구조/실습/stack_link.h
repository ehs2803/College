#ifndef __STACK_LINK_H__
#define __STACK_LINK_H__
#include<stdbool.h>
#define MAX 100

typedef struct nodeRecord_stack{
	int Data;
	struct nodeRecord_stack* Next;
}node_stack;
typedef node_stack* Nptr_stack;

void Inint_stack_link(node_stack**Top);

void Push_link(node_stack** Top, int item);

int Pop_link(node_stack** Top);

bool IsEmpty_stack_link(node_stack** Top);

void getTop_link(node_stack** Top, int* item);

void FreeStack_link(node_stack** Top);

#endif
//20200706-4