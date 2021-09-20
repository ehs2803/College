#include<stdio.h>

int main(void)
{
	int i, j, k = 0;
	int a[2][2] = { 0 };
	int b[2][2] = { 0 };
	int c[2][2] = { 0 };

	printf("1행을 입력하시오 : ");
	scanf_s("%d %d",&a[0][0],&a[0][1]);

	printf("2행을 입력하시오 : ");
	scanf_s("%d %d", &a[1][0], &a[1][1]);

	b[0][0] = a[1][1];
	b[0][1] = -a[0][1];
	b[1][0] = -a[1][0];
	b[1][1] = a[0][0];

	k = 1 / ((a[0][0] * a[1][1]) - (a[0][1] * a[1][0]));

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			c[i][j] = k * b[i][j];
		}
		
	}
	
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}
//20191010

