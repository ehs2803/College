#include<stdio.h>

int main(void)
{
	char a;

	printf("���ڸ� �Է��Ͻÿ�: ");
	a = getchar();

	if (a == 'R' || a == 'r')
	{
		printf("Rectangle");
	}
	else if (a == 'C' || a == 'c')
	{
		printf("Circle");
	}
	else if (a == 'T' || a == 't')
	{
		printf("Triangle");
	}
	else
	{
		printf("Unknown");
	}
}