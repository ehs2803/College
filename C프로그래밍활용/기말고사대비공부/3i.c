#define _CRT_SECURE_NO_WARNING
#include<stdio.h>

int main(void)
{
	char a[10];
	int c;

	FILE* fp = NULL;
	printf("�����̸�:");
	scanf("%s", a);
	fp = fopen(a, "w");
	if (fp == NULL)
	{
		printf("���� ���� ����!\n");
	}
	else
	{
		printf("���� ���� ����!\n");
	}
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fclose(fp);//�Է�

	fp = fopen(a, "r");
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
    fclose(fp);//���
}
//20191130