#include<stdio.h>

void print_binary(int x);

int main(void)
{
	int num;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &num);

	printf("%d의 이진수는 =  ", num);
	print_binary(num);

}

void print_binary(int x)
{
	if (x > 0)
	{
		print_binary(x / 2);
		printf("%d", x % 2);
	}
}