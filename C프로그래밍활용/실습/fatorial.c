#include<stdio.h>
long factorial(int n);

int main()
{
	int result = 0;
	int num = 0;

	printf("정수를 입력하시오: ");
	scanf_s("%d", num);

	result = factorial(num);
	printf("%d! = %d 입니다",num,result);

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