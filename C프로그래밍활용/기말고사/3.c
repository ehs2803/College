#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct book {
	char title[20];
	char name[20];
	char home[20];
}BOOK;

void menu();
void add();
void print();
void search();

BOOK a[100];
int num = 0;

int main(void)
{
	int number;
	while (1)
	{
		menu();
    printf("�������� �Է��Ͻÿ�");
	scanf("%d", &number);
	getchar();
	if (number == 1)
	{
		add();
	}
	else if (number == 2)
	{
		print();
	}
	else if (number == 3)
	{
		search();
	}
	else if (number == 4)
	{
		return 0;
	}

	}
	
}

void menu()
{
	printf("==================\n");
	printf(" 1. �߰�\n");
	printf(" 2. ���\n");
	printf(" 3. �˻�\n");
	printf(" 4. ����\n");
	printf("==================\n");
}

void add()
{
	printf("������ �̸�:"); gets_s(a[num].title, 20);
	printf("����:"); gets_s(a[num].name, 20);
	printf("���ǻ�:"); gets_s(a[num].home, 20);
	num++;
}

void print()
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("�������̸�:%s\n", a[i].title);
		printf("����:%s\n", a[i].name);
		printf("���ǻ�:%s\n", a[i].home);
	}
}

void search()
{
	char sname[20];
	int i;
	printf("�˻��� �����̸�:"); gets_s(sname, 20);
	for (i = 0; i <= num; i++)
	{
		if (strcmp(sname, a[i].title) == 0)
		{
			printf("�������̸�:%s\n", a[i].title);
			printf("����:%s\n", a[i].name);
			printf("���ǻ�:%s\n", a[i].home);
			return 0;
		}
	}
	printf("�ش絵������\n");
}