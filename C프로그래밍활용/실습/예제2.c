#define _CRT_SECURE_NO_WARNING
#include<stdio.h>

int main(void)
{
	FILE* fp = NULL;
	int c;
	
	fp = fopen("sample.txt", "r");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
	}
	else
	{
		printf("파일 열기 성공\n");
	}
	while ((c = fgetc(fp)) != EOF)//EOF는 문자열의끝에 나타남. 문자열 끝에 -1이 들어감.
	{
		putchar(c);
		//printf("%c",c);
	}
	fclose(fp);
}