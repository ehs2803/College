#include<stdio.h>

int main(void)
{
	int a, b;
	float c;

	printf("질량(kg): ");
	scanf_s("%d", &a);
	printf("속도(m/s): ");
	scanf_s("%d", &b);

	c = 0.5 * a * b * b;

	printf("운동에너지(J): %lf", c);
}