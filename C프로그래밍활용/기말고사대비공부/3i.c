#define _CRT_SECURE_NO_WARNING
#include<stdio.h>

int main(void)
{
	char a[10];
	int c;

	FILE* fp = NULL;
	printf("파일이름:");
	scanf("%s", a);
	fp = fopen(a, "w");
	if (fp == NULL)
	{
		printf("파일 열기 실패!\n");
	}
	else
	{
		printf("파일 열기 성공!\n");
	}
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fclose(fp);//입력

	fp = fopen(a, "r");
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
    fclose(fp);//출력
}
//20191130