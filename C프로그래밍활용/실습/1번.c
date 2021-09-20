#include<stdio.h>

int main(void)
{
	char a;
	int b;

	printf("문자를 입력하시오 : ");
	scanf_s("%c", &a);
	printf("아스키 코드 : %d\n", a);

	printf("아스키 코드 값을 입력 : ");
	scanf_s("%d", &b);
	printf("문자는 : %c", b);
}