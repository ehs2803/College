#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

void menu();
void add(FILE* fpp);
void search(FILE* fpp);
void updata(FILE* fpp);

typedef struct person {
	int num;
	char name[20];
	char phone[20];
}PERSON;

int main(void)
{
	FILE* fp;
	int innum;
	fp = fopen("BOOK2.txt", "a+");
	if (fp == NULL)
	{
		fprintf(stderr, "������ �� �� �����ϴ�.\n");
		return 0;
	}
	while (1)
	{
		menu();
		printf("�׸��� �Է�:");
		scanf("%d", &innum);
		getchar();
		if (innum == 1)
		{
			add(fp);
		}
		else if (innum == 2)
		{
			search(fp);
		}
		else if (innum == 3)
		{
			updata(fp);
		}
		else if (innum == 4)
		{
			fclose(fp);
			return 0;
		}

	}
}

void menu()
{
	printf("=====================\n");
	printf(" 1. �߰�\n");
	printf(" 2. �˻�\n");
	printf(" 3. ����\n");
	printf(" 4. ����\n");
	printf("=====================\n");
}

void add(FILE* fpp)
{
	PERSON data;

	printf("�й�:");
	scanf("%d", &data.num);
	getchar();
	printf("�̸�:");
	gets_s(data.name, 20);
	printf("��ȭ��ȣ:");
	gets_s(data.phone, 20);

	fseek(fpp, 0, SEEK_END);
	fprintf(fpp, " %d %s %s", data.num, data.name, data.phone);//fprintf(fpp, "%d %s %s ", data.num, data.name, data.phone); �̷����̸�
}                                                              //������ �����Ͱ� �˻� �� �ι���µ�

void search(FILE* fpp)
{
	PERSON data;
	char sname[20];

	printf("ã�� �̸�:");
	scanf("%s", sname);

	fseek(fpp, 0, SEEK_SET);
	while (!feof(fpp))
	{
		fscanf(fpp, "%d %s %s", &data.num, &data.name, &data.phone);
		if (strcmp(data.name, sname) == 0)
		{
			printf("�й�:%d\n", data.num);
			printf("�̸�:%s\n", data.name);
			printf("��ȭ��ȣ:%s\n",data.phone);
		
		}
	}
}

void updata(FILE* fpp)
{
	PERSON data;
	char sname[20];

	printf("������ �̸�:");
	scanf("%s", sname);

	fseek(fpp, 0, SEEK_SET);
	while (!feof(fpp))
	{
		fscanf(fpp, "%d %s %s", &data.num, &data.name, &data.phone);
		if (strcmp(data.name, sname) == 0)
		{
			printf("�й�:");
			scanf("%d", &data.num);
			getchar();
			printf("�̸�:");
			gets_s(data.name, 20);
			printf("��ȭ��ȣ:");
			gets_s(data.phone, 20);
			fseek(fpp, 0, SEEK_SET);
			fprintf(fpp, "%d %s %s\n", data.num, data.name, data.phone);
			return 0;
		}
	}
}
//20191211 + 20191212