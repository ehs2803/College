#include<stdio.h>
#define _CRT_SECURE_NO_WARNING

int main(void)
{
	char a[10];
	char b[10];

	FILE* fp = NULL;

	printf("파일 이름:");
	scanf("%s", a);
	fp = fopen(a, "w");
	if (fp == NULL)
	{
		printf("실패\n");
	}
	else
	{
		printf("성공\n");
	}
	fclose(fp);
	//파일 열기 및 파일 생성

	printf("삭제할파일:");
	scanf("%s", b);
	if (remove(b) == -1)
	{
		printf("삭제 못함\n");
	}
	else
	{
		printf("삭제 성공\n");
	}
	//파일 삭제, 만약에 해당하는 파일 없으면 삭제못함
}
//20191130