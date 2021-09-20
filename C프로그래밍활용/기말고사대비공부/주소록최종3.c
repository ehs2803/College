#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct person {
	int num;
	char name[20];
	char phone[20];
	char address[20];
}PERSON;

void menu();
void add(FILE* fp);
void update(FILE* fp, FILE* fq);
void searcha(FILE* fp);
void searchb(FILE* fq);

int main(void)
{
	FILE* fp, * fq;
	int num, num1;
	fp = fopen("BOOKF.bin", "a+");
	fq = fopen("BOOKFF.bin", "a+");
	while (1)
	{
		menu();
		printf("항목선택:"); scanf("%d", &num);
		if (num == 1)
		{
			add(fp);
		}
		else if (num == 2)
		{
			update(fp, fq);
		}
		else if (num == 3)
		{
			printf("1.수정전, 2.수정후"); scanf("%d", &num1);
			if (num1 == 1)
			{
				searcha(fp);
			}
			else if (num1 == 2)
			{
				searchb(fq);
			}
		}
		else if (num == 4)
		{
			fclose(fp);
			fclose(fq);
			return 0;
		}
	}
}

void menu()
{
	printf("===================\n");
	printf(" 1. add\n");
	printf(" 2. update\n");
	printf(" 3. search\n");
	printf(" 4. end\n");
	printf("===================\n");
}

void add(FILE* fp)
{
	PERSON data;
	printf("number:"); scanf("%d", &data.num);
	printf("name"); scanf("%s", data.name);
	printf("phone"); scanf("%s", data.phone);
	printf("address"); scanf("%s", data.address);
	fseek(fp, 0, SEEK_END);
	fwrite(&data, sizeof(data), 1, fp);
}

void update(FILE* fp, FILE* fq)
{
	PERSON data;
	int i;
	char sname[20];
	printf("update name:"); scanf("%s", sname);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, sname) == 0)
		{
			printf("number:"); scanf("%d", &data.num);
			printf("name"); scanf("%s", data.name);
			printf("phone"); scanf("%s", data.phone);
			printf("address"); scanf("%s", data.address);
			fseek(fq, 0, SEEK_END);
			fwrite(&data, sizeof(data), 1, fq);
		}
	}

}

void searcha(FILE* fp)
{
	PERSON data;
	int i;
	char sname[20];
	printf("search name:"); scanf("%s", sname);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, sname) == 0)
		{
			printf("number:%d\n", data.num);
			printf("name:%s\n", data.name);
			printf("phone:%s\n", data.phone);
			printf("address:%s\n", data.address);
			return 0;
		}
	}
}

void searchb(FILE* fq)
{
	PERSON data;
	int i;
	char sname[20];
	printf("search name:"); scanf("%s", sname);
	fseek(fq, 0, SEEK_SET);
	while (!feof(fq))
	{
		fread(&data, sizeof(data), 1, fq);
		if (strcmp(data.name, sname) == 0)
		{
			printf("number:%d\n", data.num);
			printf("name:%s\n", data.name);
			printf("phone:%s\n", data.phone);
			printf("address:%s\n", data.address);
			return 0;
		}
	}
}
//20191214