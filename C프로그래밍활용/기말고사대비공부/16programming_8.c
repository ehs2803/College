#include<stdio.h>

int main(void)
{
	char str[100];
	char* token;

	int count = 1;
	printf("문자열을 입력하시오 : ");
	gets(str);

	token = strtok(str, " ");

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
		{
			count++;
		}
	}
	printf("단어의 수 : %d\n", count);
}
//20191110