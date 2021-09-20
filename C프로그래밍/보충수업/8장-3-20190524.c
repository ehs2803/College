#include<stdio.h>
double area();

int main(void)
{
	double a;

	printf("원의 반지름을 입력하시오: ");
	scanf_s("%lf", &a);

	printf("원의 면적은 %lf입니다. ", area(a));

}

double area(double i)
{
	return 3.14 * i * i;
}