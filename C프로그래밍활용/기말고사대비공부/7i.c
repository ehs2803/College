#include<stdio.h>
#define _CTR_SECURE_NO_WARNING

int main(void)
{
	FILE* fp;

	char fname[10];
	char name[10];
	int number, count = 0;
	float score, total = 0;

	printf("�������� �̸��� �Է��Ͻÿ�:");
	scanf("%s", fname);

	fp = fopen(fname, "w");
	if (fp == NULL)
	{
		fprintf(stderr, "�������� %s�� �� �� �����ϴ�.\n", fname);
		exit(1);
	}
	else
	{
		printf("���� ���� ����\n");
	}

	while (1)
	{
		printf("�й�, �̸�, ������ �Է��Ͻÿ�: (�����̸� ����)");
		scanf("%d", &number);
		if (number < 0)
		{
			break;
		}
		scanf("%s %f", name, &score);
		fprintf(fp, " %d %s %f", number, name, score);
	}
	fclose(fp);

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		fprintf(stderr,"���� ���� %s�� �� �� �����ϴ�.\n",fname);
		exit(1);
	}
	else
	{
		printf("���� ���� ����\n");
	}

	while (!feof(fp))
	{
		fscanf(fp, " %d %s %f", &number, name, &score);
		total = total + score;
		count++;
	}
	fclose(fp);
	printf("��� = %f\n", total / count);
	
}
//20191130