#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int a[10];

	int i, j, temp, least;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("\n");
	for (i = 0; i < 9; i++)
	{
		least = i;
		for (j = i + 1; j < 10; j++)
		{
			if (a[j] > a[least])
			{
				least = j;
			}
		}
		temp = a[i];
		a[i] = a[least];
		a[least] = temp;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

}
//20191214