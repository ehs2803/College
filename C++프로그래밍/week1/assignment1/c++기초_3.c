#include<stdio.h>

int main(void)
{
	int num;
	int i, j;

	printf("정수 입력>>");
	scanf_s("%d", &num);

	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}