#define _CRT_SECURE_NO_WARNING
#include<stdio.h>

int main(void)
{
	FILE* fp = NULL;
	int c;
	
	fp = fopen("sample.txt", "r");
	if (fp == NULL)
	{
		printf("���� ���� ����\n");
	}
	else
	{
		printf("���� ���� ����\n");
	}
	while ((c = fgetc(fp)) != EOF)//EOF�� ���ڿ��ǳ��� ��Ÿ��. ���ڿ� ���� -1�� ��.
	{
		putchar(c);
		//printf("%c",c);
	}
	fclose(fp);
}