#include<stdio.h>
#define _CRT_SECURE_NO_WARNING

int main(void)
{
	char a[10];
	char b[10];

	FILE* fp = NULL;

	printf("���� �̸�:");
	scanf("%s", a);
	fp = fopen(a, "w");
	if (fp == NULL)
	{
		printf("����\n");
	}
	else
	{
		printf("����\n");
	}
	fclose(fp);
	//���� ���� �� ���� ����

	printf("����������:");
	scanf("%s", b);
	if (remove(b) == -1)
	{
		printf("���� ����\n");
	}
	else
	{
		printf("���� ����\n");
	}
	//���� ����, ���࿡ �ش��ϴ� ���� ������ ��������
}
//20191130