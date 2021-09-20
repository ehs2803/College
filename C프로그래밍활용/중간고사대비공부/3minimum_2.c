#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

int main(void)
{
	int list[SIZE] = { 0 };
	int i, max;

	printf("------------------------------------------------\n");
	printf("1  2  3  4  5  6  7  8 9  10\n");
	printf("------------------------------------------------\n");

	srand(time(NULL));

	for (i = 0; i < SIZE; i++)
	{
		list[i] = ((rand() % 100) + 1);
		printf("%-3d", list[i]);
	}
	printf("\n\n");

	max = list[0];

	for (i = 1; i < SIZE; i++)
	{
		if (list[i] > max)
		{
			max = list[i];
		}
	}
	printf("최솟값은 %d입니다.\n", max);
}
//20191011