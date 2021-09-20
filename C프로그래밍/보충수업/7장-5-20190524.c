#include<stdio.h>

int main(void)
{
	int a, i, j;

	printf("정수를 입력하시오: ");
	scanf_s("%d", &a);

	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d ", j);
		}
		printf("\n");
	}
}