#include<stdio.h>
long factorial(int n);

int main()
{
	int result = 0;
	int num = 0;

	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", num);

	result = factorial(num);
	printf("%d! = %d �Դϴ�",num,result);

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