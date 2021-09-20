#include<stdio.h>

int main(void)
{
	char a;

	printf("문자를 입력하시오: ");
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