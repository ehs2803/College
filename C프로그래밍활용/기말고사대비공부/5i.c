#include<stdio.h>
#define _CRT_SECURE_NO_WARNINH

int main(void)
{
	FILE* fp1, * fp2;
	char file1[10];
	char buffer[100];

	printf("���� �̸�: ");
	gets("%s",file1);
	fp1 = fopen(file1, "w");
	if (fp1 == NULL)
	{
		fprintf(stderr, "���� %s�� ��������\n", file1);
		exit(1);
	}
	else
	{
		printf("���� ���� ����\n");
	}
    
	printf("�Է��� ������ �Է��Ͻÿ�: ");
	gets(buffer);

	fputs(buffer, fp1);
	
	fclose(fp1);	
}
//20191130