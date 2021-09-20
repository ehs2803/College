#include<stdio.h>

void swap(int* a, int* b);

int main(void)
{
	int a = 100, b = 200;

	printf("a=%d b=%d\n", a, b);
	swap(&a,&b);
	printf("a=%d b=%d\n", a, b);
}

void swap(int* a, int* b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
//20191015