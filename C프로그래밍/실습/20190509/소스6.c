#include<stdio.h>

int main(void)
{

	int n;
	int i;
	int sum=0;

	

	for (i = 1; i <= 5; i++)
	{
		printf("값을 입력하시오");
		scanf_s("%d", &n);
		sum = sum +n;

	}

	printf("합계는 %d입니다.", sum);

}