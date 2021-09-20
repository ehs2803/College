#include<stdio.h>
int scalar_mult(int a[][3], int scalar);
int transpose(int a[][3], int b[][3]);

int main(void)
{
	int matrix1[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int matrix2[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int matrix3[3][3] = { 0 };

	scalar_mult(matrix1, 2);
	printf("\n");
	transpose(matrix2, matrix3);

}

int scalar_mult(int a[][3], int scalar)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			a[i][j] = 2 * a[i][j];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}

int transpose(int a[][3], int b[][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			b[i][j] = a[j][i];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}
//20191018