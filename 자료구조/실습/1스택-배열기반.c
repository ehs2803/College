#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef struct arraystack
{
	int stackarr[STACK_LEN];
	int topindex;
}Stack;

void StackInti(Stack* pstack)
{
	pstack->topindex = -1;
}

int SIsempty(Stack* pstack)
{
	if (pstack->topindex == -1)
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
	pstack->topindex += 1;
	pstack->stackarr[pstack->topindex] = data;
}

int Spop(Stack* pstack)
{
	int ridx;

	if (SIsempty(pstack))
	{
		printf("stack memory empty!!");
		exit(-1);
	}

	ridx = pstack->topindex;
	pstack->topindex -= 1;

	return pstack->stackarr[ridx];
}

int Speek(Stack* pstack)
{
	if (SIsempty(pstack))
	{
		printf("stack memory empty!!");
		exit(-1);
	}

	return pstack->stackarr[pstack->topindex];
}

int main(void)
{
	Stack stack;
	StackInti(&stack);

	Spush(&stack, 1); Spush(&stack, 2);
	Spush(&stack, 3); Spush(&stack, 4);
	Spush(&stack, 5);

	while (!SIsempty(&stack))
	{
		printf("%d ", Spop(&stack));
	}
}
//20200113