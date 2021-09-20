#include<stdio.h>

void print_binary(int a);

int main(void)
{
	int a;
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &a);
	print_binary(a);
}

void print_binary(int a)
{
	if (a > 0)
	{
		print_binary(a / 2);
		printf("%d", a % 2);
	}
}
//20191010