#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

int main(void)
{
	int a[SIZE] = { 0 };
	int b,i, j, temp, least;
	srand(time(NULL));

	for (b=0;b<SIZE;b++)
	{
		a[b] = rand() % 100;
	}
	for (b= 0; b< SIZE; b++)
	{
		printf("%d ", a[b]);
	}

	printf("\n");

	for (i = 0; i < SIZE - 1; i++)
	{
		least = i;
		for (j = i + 1; j < SIZE; j++)
			if (a[j] < a[least])
				least = j;
		temp = a[i];
		a[i] = a[least];
		a[least] = temp;
	}


	for (b= 0;b< SIZE; b++)
	{
		printf("%d ", a[b]);
	}


}