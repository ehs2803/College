#include<stdio.h>

int main(void)
{
	int a, b;
	float c;

	printf("����(kg): ");
	scanf_s("%d", &a);
	printf("�ӵ�(m/s): ");
	scanf_s("%d", &b);

	c = 0.5 * a * b * b;

	printf("�������(J): %lf", c);
}