#include<stdio.h>

int main(void)
{
	int a;

	printf("정수를 입력하시오: ");
	scanf_s("%d", &a);

	printf("십의 자리:%d \n", a / 10);
	printf("일의 자리:%d \n", a % 10);
}