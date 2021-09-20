#include<stdio.h>

int main(void)
{
	char s[20];

	printf("문자열을 입력하시오: ");
	scanf_s("%[abc]s", s, 20);

	printf("%s", s);

}
//20191128