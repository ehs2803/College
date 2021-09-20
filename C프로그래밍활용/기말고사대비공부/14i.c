#include<stdio.h>
#define _CRT_SECURE_NO_WARNING
int main(void)
{
	FILE* fp1,*fp2;
	char fname[10];
	char cfname[10];
	int c;

	printf("열 파일 이름 입력: ");
	scanf("%s", fname);
	fp1 = fopen(fname, "r");
	if (fp1 == NULL)
	{
		printf("파일%s을 열수 없습니다.\n", fname);
		exit(1);
	}
	else
	{
		printf("파일열기 성공\n");
	}

	printf("복사할 파일 이름: ");
	scanf("%s", cfname);
	fp2 = fopen(cfname, "w");
	if (fp2 == NULL)
	{
		printf("파일%s을 열수 없습니다.\n", cfname);
		exit(1);
	}
	else
	{
		printf("파일열기 성공\n");
	}

	while ((c = fgetc(fp1))!=EOF)
	{
		if ('a' <= c && c <= 'z')
		{
			c = c - 32;
		}
		fputc(c, fp2);
		putchar(c);
	}
	fclose(fp1);
	fclose(fp2);
}
//20191201 success