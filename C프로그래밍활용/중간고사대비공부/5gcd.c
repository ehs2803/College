#include<stdio.h>

int gcd(int a, int b);

int main(void)
{
	int a, b;
	printf("������ �Է��Ͻÿ� : ");
	scanf_s("%d %d", &a, &b);
	printf("%d %d�� �ִ������� %d", a, b, gcd(a, b));
}

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}
//20191010