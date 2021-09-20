#include<stdio.h>

int main(void)
{
	int gugudan[10][10];
	int i, j;

	for (i = 2; i < 10; i++)
	{
		printf("%d´Ü : ", i);
		for (j = 1; j < 10; j++)
		{
			gugudan[i][j] = i * j;
		    printf("%3d", gugudan[i][j]);
		}
		printf("\n");
	}
}