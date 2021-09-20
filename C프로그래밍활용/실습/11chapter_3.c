#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void array_fill(int* a, int size);
void array_print(int* a, int size);

int main(void)
{
	int data[SIZE] = { 0 };
	array_fill(data, SIZE);
	array_print(data, SIZE);
}

void array_fill(int* a, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		a[i] = rand()%1000;
	}
}

void array_print(int* a, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}