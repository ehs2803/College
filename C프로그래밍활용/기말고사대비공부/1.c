#include<stdio.h>
#define _CRT_SECURE_NO_WARNING

int main(void)
{

	int c;

	FILE* fp = NULL;


	fp = fopen("s.txt", "w");

	if (fp == NULL)
	{
		printf("���� ���� ����\n");
	}
	else
	{
		printf("���� ���� ����\n");
	}
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	fclose(fp);

}
//20191128