#include<stdio.h>
//#include<ctype.h>

int main(void)
{
	FILE* fp;
	char fname[10];
	int count = 0;
	int c;
	printf("���� �̸��� �Է��Ͻÿ�: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "���� %s�� ���� ����\n", fname);
	}
	else
	{
		printf("���� ���� ����\n");
	}
	while ((c = fgetc(fp)) != EOF)
	{
		if (isprint(c))
		{
			count++;
		}
	}
	fclose(fp);
	printf("������ ������ %d", count);

}
//20191201 success