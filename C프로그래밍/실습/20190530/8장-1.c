#include<stdio.h>
double square(double i);

int main(void)
{
	float a;

	printf("정수를 입력하시오: ");
	scanf_s("%f", &a);

	printf("주어진 정수 %f의 제곱은 %f입니다.", a, square(a));

}

double square(double i)
{
	return i * i;
}