#include<stdio.h>
#define SQMETER_PER_PYEONG 3.3058

int main(void)
{
	int a;
	float b;

	printf("평을 입력하세요: ");
	scanf_s("%d", &a);

	b = SQMETER_PER_PYEONG * a;

	printf("%f평방미터입니다.", b);
}