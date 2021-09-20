#include<stdio.h>
int year(int i);

int main(void)
{
	int a;

	printf("연도를 입력하시오: ");
	scanf_s("%d", &a);

	printf("%d년은 %d일입니다.", a, year(a));
}

int year(int i)
{
	if (((i & 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
	{
		return 365;
	}
	else
	{
		return 366;
	}
}