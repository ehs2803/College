#include<stdio.h>

int main(void)
{
	FILE* fp;
	char fname[10];
	char buffer[256];
	int line_num = 0;
	printf("���� �̸�: ");
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
	while (fgets(buffer, 256, fp))
	{
		line_num++;
		printf("%d: %s",line_num, buffer);
	}
	fclose(fp);
}
//20191201 success