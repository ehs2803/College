#include<stdio.h>

int main(void)
{
	int a, b, c;

	if (scanf_s("%d%d%d", &a, &b, &c) == 3)
	{
		printf("정수들의 합은 %d\n", a + b + c);
	}
	else
	{
		printf("입력된 값이 올바르지 않습니다\n");
	}
}
//20191128