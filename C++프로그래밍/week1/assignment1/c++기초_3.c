#include<stdio.h>

int main(void)
{
	int num;
	int i, j;

	printf("���� �Է�>>");
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