#include<stdio.h>

int main(void)
{
	int list[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int i, j, temp, least;

	for (i = 0; i < 9; i++)
	{
		least = i;
		for (j = i + 1; j < 10; j++)
			if (list[j] < list[least])
				least = j;
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;

	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", list[i]);
	}
}