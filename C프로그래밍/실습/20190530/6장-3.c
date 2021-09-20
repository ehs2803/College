#include<stdio.h>

int main(void)
{
	int a, b, c, min;

	printf("3개의 정수를 입력하시오: ");
	scanf_s("%d %d %d", &a, &b, &c);

	min = a < b ? a : b;
	min = min < c ? min : c;

	printf("제일 작은 정수는 %d입니다.", min);
}