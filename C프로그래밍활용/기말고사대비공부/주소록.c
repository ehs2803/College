#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void mnun();
void add(FILE* fpp);
void search(FILE* fpp);

typedef struct book {
	char name[10];
	char phone[15];
	char adderss[20];
	char feature[20];
}PERSON;


int main(void)
{
	FILE* fp;
	int num;
	fp = fopen("BOOK.txt", "a+");
	if (fp == NULL)
	{
		fprintf(stderr, "������ �� �� �����ϴ�.\n");
		exit(1);
	}
	while (1)
	{
		mnun();
		printf("����� �����Ͻðڽ��ϱ�? ");
		scanf("%d", &num);
		getchar();

		if (num == 1)
		{
			add(fp);
		}
		else if (num == 2)
		{

		}
		else if (num == 3)
		{
			search(fp);
		}
		else if (num == 4)
		{
			fclose(fp);
			return 0;
		}
	}
}

void mnun()
{
	printf("====================\n");
	printf(" 1. �߰�\n");
	printf(" 2. ����\n");
	printf(" 3. �˻�\n");
	printf(" 4. ����\n");
	printf("====================\n");
}

void add(FILE* fpp)
{
	PERSON data;

	printf("�̸�:");
	gets_s(data.name, 10);
	printf("��ȭ��ȣ:");
	gets_s(data.phone, 15);
	printf("�ּ�:");
	gets_s(data.adderss, 20);
	printf("Ư¡");
	gets_s(data.feature, 20);

	fseek(fpp, 0, SEEK_END);
	fprintf(fpp, "%s %s %s %s\n", data.name, data.phone, data.adderss, data.feature);
}

void search(FILE* fpp)
{
	PERSON data;
	char sname[20];

	printf("ã�� �̸��� �Է��Ͻÿ�:");
	gets_s(sname, 20);

	fseek(fpp, 0,SEEK_SET);
	while (!feof(fpp))
	{
		fscanf(fpp,"%s %s %s %s", data.name, data.phone, data.adderss, data.feature);
		if (strcmp(data.name, sname) == 0)
		{
			printf("�̸�:%s\n", data.name);
			printf("��ȭ��ȣ:%s\n", data.phone);
			printf("�ּ�:%s\n", data.adderss);
			printf("Ư¡:%s\n", data.feature);
			return 0;
		}
	}
	printf("ã�� ����� �����ϴ�.\n");
}
//20191207