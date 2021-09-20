#include<stdio.h>

int factorial(int a);

int main(void)
{
	int a;

	printf("정수를 입력하시오 : ");
	scanf_s("%d", &a);
	printf("%d! is %d.\n", a, factorial(a));
}

int factorial(int a)
{
	printf("factorial(%d)\n", a);

	if (a==1)
	{
		return 1;
	}
	else
	{
		return a * factorial(a - 1);
	}
}
//20191010