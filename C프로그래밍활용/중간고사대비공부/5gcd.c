#include<stdio.h>

int gcd(int a, int b);

int main(void)
{
	int a, b;
	printf("정수를 입력하시오 : ");
	scanf_s("%d %d", &a, &b);
	printf("%d %d의 최대공약수는 %d", a, b, gcd(a, b));
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