#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNING

int main(void)
{
	char a[20];
	int i;
	int len;
	gets(a);

	for (i = 0; a[i] != '\0'; i++)
	{
		if ('A' <= a[i] && a[i] <= 'Z')
		{
			a[i] = a[i] + 32;
		}
	}
	len = strlen(a);

	for (i = 0; i < len ; i++)
	{
		if (a[i] == a[len - (i + 1)])
		{

		}
		else
		{
			printf("회문이 아닙니다.");
			return 0;
		}
	}
	printf("회문입니다.");


}
//20191129
//20191215 edit line21 len-1 -> len