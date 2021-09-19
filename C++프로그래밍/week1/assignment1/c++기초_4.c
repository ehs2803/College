#include<stdio.h>

int main(void)
{
	double number[5];
	int i;
	double avg = 0;

	printf("실수 5개 입력>>");
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
	printf("의 평균 = %.2lf", avg);
}