#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
	int data;
	struct node* next;
}Node;

typedef struct liststack
{
	Node* head;
}Stack;

void Stackinit(Stack* pstack)
{
	pstack->head = NULL;
}

int Sisempty(Stack* pstack)
{
	if (pstack->head == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Spush(Stack* pstack, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->data = data;
	newnode->next = pstack->head;

	pstack->head = newnode;
}

int Spop(Stack* pstack)
{
	int rdata;
	Node* rnode;

	if (Sisempty(pstack))
	{
		printf("stack memory empty!!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

int Speek(Stack* pstack)
{
	if (Sisempty(pstack))
	{
		printf("stack memory empty!!");
		exit(-1);
	}

	return pstack->head->data;
}

int main(void)
{
	Stack stack;
	Stackinit(&stack);

	Spush(&stack, 1); Spush(&stack, 2);
	Spush(&stack, 3); Spush(&stack, 4);
	Spush(&stack, 5);

	while (!Sisempty(&stack))
	{
		printf("%d ", Spop(&stack));
	}
}
//20200113