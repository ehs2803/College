#include<stdio.h>

int main(void)
{
	int n, sum;
	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);

	printf("자리수의 합: ");
	
}
/*
#include <stdio.h>
int get_digit_sum(int num);
int main()
{
	int n, sum;
	printf("정수를 입력하시오: ");
	scanf("%d", &n);
	sum = get_digit_sum(n);

	printf("자리수의 합: %d\n", sum);

	return 0;
}

int get_digit_sum(int n)
{
	if (n == 0)
		return 0;

	return ((n % 10) + get_digit_sum(n / 10));
}

*/