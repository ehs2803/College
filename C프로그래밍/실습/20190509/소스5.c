#include<stdio.h>

int main(void)
{

	int a;
	int i;
	int sum;

	

	printf("정수를 입력하시오.");
	scanf_s("%d", &a);
	
	i = 1;
	sum = 0;

	while (i <= a)
	{
		sum = sum + i;
		i++;
	}

	printf("1부터 %d까지 합은 %d입니다.", a, sum);

}