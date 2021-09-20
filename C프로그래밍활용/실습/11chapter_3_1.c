#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void array_fill(int* a, int size);
void array_print(int* a, int size);
void sum(int* a);

int main(void)
{
	int data[SIZE] = { 0 };
	array_fill(data, SIZE);
	array_print(data, SIZE);
	sum(data);
}

void array_fill(int* a, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 10;
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

void sum(int* a)
{
	int sum = 0;
	int i;

	for (i = 0; i < SIZE; i++)
	{
		sum = sum + a[i];
	}
	printf("гу = %d", sum);
}