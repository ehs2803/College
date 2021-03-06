#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define size 15

int main(void)
{
	int prices[size] = { 0 };
	int i, minimum;

	printf("----------------------------------------------------\n");
	printf("1  2  3  4  5  6  7  8  9  10 11 12 13 14 15\n");
	printf("----------------------------------------------------\n");
	
	srand((unsigned)time(NULL));
	for (i = 0; i < size; i++)
	{
		prices[i] = (rand() % 100) + 1;
		printf("%-3d", prices[i]);
	}

	printf("\n\n");

	minimum = prices[0];

	for (i = 1; i < size; i++)
	{
		if (prices[i] < minimum)
		{
			minimum = prices[i];
		}
	}
	printf("최솟값은 %d입니다.\n", minimum);
}