#include<stdio.h>

int main(void)
{
	int a;

	printf("카운터의 초기값을 입력하시오: ");
	scanf_s("%d", &a);

	for (a = a; a > 0; a--)
	{
		printf("%d ", a);
	}

	printf("\a");
}