#include<stdio.h>

int main(void)
{
	int n, r,i,result;

	result = 1;

	printf("n의 값: ");
	scanf_s("%d", &n);

	printf("r의 값: ");
	scanf_s("%d", &r);

	for (i = n; i >= n - r - 1; i--)
	{
		result = result * i;
	}

	printf("순열의 값은 %d입니다.", result);

}