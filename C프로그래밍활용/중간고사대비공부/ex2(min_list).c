#include<stdio.h>

#define SIZE 6

int main(void)
{
	int list[6] = { 80,41,35,90,40,20 };


	int i, j, temp, least;

	for (i = 0; i < SIZE - 1; i++)
	{

		least = i;

		for (j = i + 1; j < SIZE; j++)
			if (list[j] < list[least])
				least = j;
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", list[i]);
	}
}
//20191009