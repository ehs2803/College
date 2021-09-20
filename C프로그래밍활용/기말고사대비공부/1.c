#include<stdio.h>
#define _CRT_SECURE_NO_WARNING

int main(void)
{

	int c;

	FILE* fp = NULL;


	fp = fopen("s.txt", "w");

	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
	}
	else
	{
		printf("파일 열기 성공\n");
	}
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	fclose(fp);

}
//20191128