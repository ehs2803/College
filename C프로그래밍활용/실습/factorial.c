#include<stdio.h>
long factorial(int n);

int mian()
{
	factorial(5);

}

long factorial(int n)
{
	printf("factorial(%d)\n", n);

	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}