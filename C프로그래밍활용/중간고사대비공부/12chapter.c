#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

int main(void)
{
	int a[SIZE] = { 0 };
	int i, j, temp, least;
	srand(time(NULL));

	for (i = 0; i < SIZE; i++)
	{
		a[i] = rand() % 100;
	}
	for (i = 0; i < SIZE;i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");

	for (i = 0; i < SIZE - 1; i++)
	{
		least = i;
		for (j = i+1;j< SIZE; j++)
		{
			if (a[j] < a[least])
			{
				least = j;
			}
			temp = a[i];
			a[i] = a[least];
			a[least] = temp;
		}
	}


	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}


}