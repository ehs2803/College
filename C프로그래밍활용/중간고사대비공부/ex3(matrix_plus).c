#include<stdio.h>

int main(void)
{
	int i, j;

	int a[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	int b[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	int c[4][4] = { 0 };

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%2d ", c[i][j]);
		}
		printf("\n");
	}

}
//20191009