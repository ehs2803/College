#include<stdio.h>

int main(void)
{
	char str[80];
	char* word[80];//이차원배열char word[100][80];이면 오류뜸.
	char* token;
	int i, count = 0;

	printf("문자열을 입력하시오 : ");
	gets_s(str, 80);//gets(str);

	token = strtok(str, " ");

	for (i = 0; token != NULL; i++)
	{
		word[i] = token;
		token = strtok(NULL, " ");
		count++;
	}
	printf("출력 문자열 :");
	for (i = 0; i < count; i++)
	{
		printf("%s ", word[count - i - 1]);
	}
}
//20191129