#include<stdio.h>

int main(void)
{
	int a, b, c;
	float d;

	printf("지팡이의 높이를 입력하시오: ");
	scanf_s("%d", &a);
	printf("지팡이 그림자의 길이를 입력하시오: ");
	scanf_s("%d", &b);
	printf("피라미드까지의 거리를 입력하시오: ");
	scanf_s("%d", &c);

	d = a * c / b;

	printf("피라미드의 높이는 %f입니다. ",d);
	
}