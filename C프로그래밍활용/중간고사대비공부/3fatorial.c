#include<stdio.h>

int factorial(int a);

int main(void)
{
	int a;

	printf("������ �Է��Ͻÿ� : ");
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