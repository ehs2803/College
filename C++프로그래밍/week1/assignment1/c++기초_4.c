#include<stdio.h>

int main(void)
{
	double number[5];
	int i;
	double avg = 0;

	printf("�Ǽ� 5�� �Է�>>");
	for (i = 0; i < 5; i++)
	{
		scanf_s("%lf", &number[i]);
	}

	for (i = 0; i < 5; i++)
	{
		printf("%.1lf ", number[i]);
		avg += number[i];
	}
	avg = avg / 5;
	printf("�� ��� = %.2lf", avg);
}