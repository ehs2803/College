#include <stdio.h>
#define SIZE 100

int main(void)
{
	int buffer[SIZE];
	FILE* fp = NULL;
	FILE* fp1 = NULL;
	int i;
	int count;
	char file1[100], file2[100];

	printf("���� ���� �̸�:  ");
	scanf("%s", file1);

	printf("���� ���� �̸�:  ");
	scanf("%s", file2);

	fp = fopen(file1, "rb");       // ��
	if (fp == NULL)
	{
		fprintf(stderr, "������ �� �� �����ϴ�.");
		return 1;
	}
	fp1 = fopen(file2, "wb");       // ��
	if (fp1 == NULL)
	{
		fprintf(stderr, "������ �� �� �����ϴ�.");
		return 1;
	}

	while ((count = fread(buffer, sizeof(char), SIZE, fp)) != 0) {
		fwrite(buffer, sizeof(char), count, fp1);
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}
//20191205