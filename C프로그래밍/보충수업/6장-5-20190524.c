#include<stdio.h>

int main(void)
{
	int a, b;

	printf("키를 입력하시오(cm): ");
	scanf_s("%d", &a);
	printf("나이를 입력하시오: ");
	scanf_s("%d", &b);

	if (a >= 140 && b >= 10)
	{
		printf("타도 좋습니다");
	}
	else
	{
		printf("죄송합니다");
	}
}