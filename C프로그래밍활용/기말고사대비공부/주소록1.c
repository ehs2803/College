#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct SS {
	char name[20];
	char phone[20];
	char address[20];
	char feature[20];
}PERSON;

void menu();
void add(FILE* fpp);
void search(FILE* fpp);

int main(void)
{
	FILE* fp;
	int num;

	fp = fopen("BOOK.dat", "ab+");
	if (fp == NULL)
	{
		fprintf(stderr, "������ �� �� ����.\n");
		exit(1);
	}
	while (1)
	{
		menu();
		printf("�׸��� �����ϼ���:");
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

void menu()
{
	printf("==========================\n");
	printf(" 1. �߰�\n");
	printf(" 2. ����\n");
	printf(" 3. �˻�\n");
	printf(" 4. ����\n");
	printf("==========================\n");
}

void add(FILE* fpp)
{
	PERSON data;
	printf("�̸�:");
	gets_s(data.name, 20);
	printf("��ȭ��ȣ:");
	gets_s(data.phone, 20);
	printf("�ּ�:");
	gets_s(data.address, 20);
	printf("Ư¡:");
	gets_s(data.feature, 20);
	fseek(fpp, 0, SEEK_END);
	fwrite(&data, sizeof(data), 1, fpp);

}

void search(FILE* fpp)
{
	PERSON data;
	char sname[20];
	printf("ã�� �̸��� ��������:");
	gets_s(sname, 20);
	fseek(fpp, 0, SEEK_SET);
	while (!feof(fpp))
	{
		fread(&data, sizeof(data), 1, fpp);
		if (strcmp(data.name, sname) == 0)
		{
			printf("��ȭ��ȣ:%s\n", data.phone);
			printf("�ּ�:%s\n", data.address);
			printf("Ư¡:%s\n", data.feature);
			return 0;
		}
	}
	printf("ã�� �� �����ϴ�.\n");
}
//20191207