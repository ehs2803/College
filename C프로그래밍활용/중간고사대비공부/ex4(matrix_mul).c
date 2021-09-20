#include<stdio.h>

int main(void)
{
	int i, j;

	int a[3][2] = {
		{1,4},
		{2,5},
		{3,6}
	};
	int b[2][3] = {
		{7,8,9},
		{10,11,12}
	};
	int c[3][3] = { 0 };

	for (i=0;i<3;i++)
	{
		c[0][i] = a[0][0] * b[0][i] + a[0][1] * b[1][i];
	}
	for (i = 0; i < 3; i++)
	{
		c[1][i] = a[1][0] * b[0][i] + a[1][1] * b[1][i];
	}
	for (i = 0; i < 3; i++)
	{
		c[2][i] = a[2][0] * b[0][i] + a[2][1] * b[1][i];
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%2d ", c[i][j]);
		}
		printf("\n");
	}
}
//20191009