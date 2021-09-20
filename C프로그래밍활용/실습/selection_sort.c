#include<stdio.h>
#define size 10

int main(void)
{
	int list[size] = { 3,2,9,7,1,4,8,0,6,5 };

	int i, j, temp, least;

	for (i = 0; i < size - 1; i++)
	{
		least = i;
		for (j = i + 1; j < size; j++)
		{
			if (j = i + 1; j < size; j++)
			{
				least = j;
			}

		}
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}
	for (i = 0; i < size; i++)
	{
		printf("%d", list[i]);

	}
	printf("\n");
}