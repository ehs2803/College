#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100

typedef struct person {
	char name[SIZE];
	char address[SIZE];
	char mobilephone[SIZE];
	char desc[SIZE];
}PERSON;

PERSON get_record();
void print_record(PERSON data);
void menu();
void add_record(FILE* fp);
void search_record(FILE* fp);
void updata_record(FILE* fp);

int main(void)
{
	FILE* fp;
	int select;

	fp = fopen("address.dat", "a+");
	if (fp == NULL)
	{
		fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	while (1)
	{
		menu();
		printf("�������� �Է��Ͻÿ�: ");
		scanf("%d", &select);
		getchar();
		if (select == 1)
		{
			add_record(fp);
		}
		else if (select == 2)
		{
			updata_record(fp);
		}
		else if (select == 3)
		{
			search_record(fp);
		}
		else if (select == 4)
		{
			return 0;
		}
	}
}

PERSON get_record()
{
	PERSON data;
	printf("�̸�: "); gets_s(data.name, SIZE);
	printf("�ּ�: "); gets_s(data.address, SIZE);
	printf("�޴���: "); gets_s(data.mobilephone, SIZE);
	printf("Ư¡: "); gets_s(data.desc, SIZE);
	return data;
}

void print_record(PERSON data)
{
	printf("�̸�:%s\n", data.name);  printf("�ּ�: %s\n", data.address);
	printf("�޴���: %s\n", data.mobilephone); printf("Ư¡: %s\n", data.desc);
}

void menu()
{
	printf("======================================\n");
	printf(" 1. �߰�\n 2. ����\n 3. �˻�\n 4. ����\n");
	printf("======================================\n");
}

void add_record(FILE* fp)
{
	PERSON data;
	data = get_record();
	fseek(fp, 0, SEEK_END);
	fwrite(&data, sizeof(data), 1, fp);
}

void search_record(FILE* fp)
{
	char name[SIZE];
	PERSON data;

	fseek(fp, 0, SEEK_SET);
	printf("Ž���ϰ��� �ϴ� ����� �̸�: ");
	gets_s(name, SIZE);
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, name) == 0)
		{
			print_record(data);
			break;
		}
	}
}


void updata_record(FILE* fp)
{
	char name[SIZE];
	PERSON data;

	fseek(fp, 0, SEEK_SET);
	printf("�����ϰ��� �ϴ� ����̸� �Է�: ");
	gets_s(name, SIZE);
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, name) == 0)
		{
			fseek(fp, 0, SEEK_CUR);
			data = get_record();
			printf("������ �Ϸ�ƽ��ϴ�.\n");
			fwrite(&data, sizeof(data), 1, fp);
			break;
		}
	}
}
//20191206