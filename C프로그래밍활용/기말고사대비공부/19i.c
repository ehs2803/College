
/*
�ؽ�Ʈ���� �״�� ����ϱ�1
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
int main(void)
{
	char a[10];
	int c;

	FILE* fp = NULL;
	printf("�����̸�:");
	scanf("%s", a);

	fp = fopen(a, "r");
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	fclose(fp);//���
}
�ؽ�Ʈ���� �״�� ����ϱ�2
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
int main(void)
{
	char a[10];
	char buffer[256];

	FILE* fp = NULL;
	printf("�����̸�:");
	scanf("%s", a);

	fp = fopen(a, "r");
	while (fgets(buffer,256,fp))
	{
		printf("%s", buffer);
	}
	fclose(fp);//���
}
�ؽ�Ʈ���Ͽ� �Է��ϱ�1
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
int main(void)
{
	char a[10];
	int c;

	FILE* fp = NULL;
	printf("�����̸�:");
	scanf("%s", a);
	getchar();//�̰� ��� ������ ������ �ؽ�Ʈ���Ͽ� ���ٶ�� �Էµ�.
	fp = fopen(a, "w");
	while ((c = getchar()) != '.')
	{
		fputc(c, fp);
	}
	fclose(fp);//���
}
�ؽ�Ʈ���Ͽ� �Է��ϱ�2
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp1;
	char file1[100];
	char buffer[1000];
	char* p;

	printf("���� �̸��� �Է��Ͻÿ�:  ");
	scanf("%s", file1);
	getchar();
	fp1 = fopen(file1, "w");
	if (fp1 == NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", file1);
		exit(1);
	}
	while (1)
	{
		p = gets(buffer);
		if (p == NULL)
		{
			break;
		}
		//fputs(buffer, fp1); �̰� ���� �ٹٲ��� �ȵ�.
		fprintf(fp1, "%s\n", buffer);  //\n�� �־ �ٹٲ� ����.
	}
	fclose(fp1);
}
*/
//20191203
