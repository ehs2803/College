#include<stdio.h>

int str_chr(char* string, char find_alpha);

int main(void)
{
	char str[80];
	char find;
	int count;

	printf("문자열을 입력하시오 ");
	gets(str);

	printf("개수를 셀 문자를 입력하시오 : ");
	scanf_s("%c", &find);

	printf("문자의 갯수 : %d", str_chr(str, find));

}

int str_chr(char* string, char find_alpha)
{
	int i = 0;
	int count = 0;
	for (i = 0; string[i] != NULL;i++)
	{
		if (string[i] == find_alpha)
		{
			count++;
		}
	}
	return count;
}