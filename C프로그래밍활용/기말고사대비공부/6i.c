#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNING

int main(void)
{
	FILE* fp;

	char fname[10];
	char buffer[256];
	char word[256];
	int line_num = 0;

	printf("���� �̸��� �Է��Ͻÿ�: ");
	scanf("%s", fname);

	printf("Ž���� �ܾ �Է��Ͻÿ�: ");
	scanf("%s", word);

	fp = fopen(fname, "r");
	
	if (fp == NULL)
	{
		fprintf(stderr,"���� %s�� �� �� ����.\n", fname);
		exit(1);
	}
	else
	{
		printf("���� ���� ����\n");
	}

	while (fgets(buffer, 256, fp))
	{
		line_num++;
		if (strstr(buffer, word))
		{
			printf("%s: %d �ܾ� %s�� �߰ߵ�\n", fname, line_num, word);
		}
	}
	fclose(fp);
}
//20191130