#include<stdio.h>

int main(void)
{
	FILE* fp1,*fp2;
	char fname[10];
	char fname1[10];
	char buffer1[256];
	char buffer2[256];
	printf("ù��° ���� �̸�: ");
	scanf("%s", fname);
	fp1 = fopen(fname, "r");
	if (fp1 == NULL)
	{
		fprintf(stderr, "���� %s�� ���� ����\n", fname);
	}
	else
	{
		printf("���� ���� ����\n");
	}
	printf("�ι�° ���� �̸�: ");
	scanf("%s", fname1);
	fp2 = fopen(fname1, "r");
	if (fp2 == NULL)
	{
		fprintf(stderr, "���� %s�� ���� ����\n", fname1);
	}
	else
	{
		printf("���� ���� ����\n");
	}
	while (fgets(buffer1,256,fp1))
	{
		fgets(buffer2, 256, fp2);
		if (strcmp(buffer1,buffer2)!=0)
		{
			printf("<< %s\n", buffer1);
			printf(">> %s\n", buffer2);
			return 0;
		}
	}
	printf("������ ���� ��ġ��");
}
//20191201 success + ������ ��� �÷��������ϱ�