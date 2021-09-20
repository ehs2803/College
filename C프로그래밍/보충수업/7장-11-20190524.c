#include<stdio.h>

int main(void)
{
	int n,i, sum;

	sum = 0;

	printf("n의 값을 입력하시오: ");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		sum = sum + i * i;
	}

	printf("계산값은 %d입니다.", sum);

}