#include<stdio.h>

int main(void)
{
	int in1, in2;
	printf("두 정수 입력>>");
	scanf_s("%d %d", &in1, &in2);

	if ((in2 % in1) == 0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}