#include<stdio.h>

int main(void)
{

	int a;
	int i;
	int sum;

	sum = 0;

	printf("정수를 입력하시오.");
	scanf_s("%d", &a);

	for (i = 1; i <= a; i++)
	{
		
		sum = sum + i;

	}

	printf("1부터 %d까지 합은 %d입니다.", a, sum);

}