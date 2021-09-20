#include<stdio.h>

int main(void)
{
	double a;

	printf("실수를 입력하시오: ");
	scanf_s("%lf", &a);

	printf("실수형식으로는 %lf입니다\n", a);
	printf("지수형식으로는 %e입니다", a);
}