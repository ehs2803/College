#include<stdio.h>

int main(void)
{
	int a, b, c,d,e;

	printf("3개의 정수를 입력하시오: ");
	scanf_s("%d %d %d", &a, &b, &c);

	d = a > b ? a : b;
	e = d > c ? d : c;

	printf("최대값:%d", e);
}