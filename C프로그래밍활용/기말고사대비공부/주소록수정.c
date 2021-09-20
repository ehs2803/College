#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100  


typedef struct person { 
	char name[SIZE];  
	char address[SIZE];  
	char mobilephone[SIZE];    
	char desc[SIZE]; 
} PERSON;

void menu();
void add_record(FILE* fp);
void search_record_a(FILE* fp);
void search_record_b(FILE* fq);
void update_record(FILE* fp, FILE* fq);

int main(void)
{
	FILE* fp, * fq;
	int select, i;
	
	if ((fp = fopen("address.txt", "a+")) == NULL || (fq = fopen("newaddress.txt", "a+")) == NULL)
	{
		fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�");
		exit(1);
	}
	while (1)
	{
		menu();  
		printf("�޴��� �����ϼ���: ");  
		scanf("%d", &select);  
		getchar();  
		if (select == 1)
		{
			add_record(fp);
		}
		else if (select == 2)
		{
			update_record(fp, fq);
		}
		else if (select == 3)
		{
			printf("1. ���� ��, 2. ���� �� : ");
			scanf("%d", &i);
			getchar();
			if (i == 1)
			{
				search_record_a(fp);
			}
			else if (i == 2)
			{
				search_record_b(fq);
			}
		}
		else if (select == 4)
		{
			fclose(fp);
			fclose(fq);
			return 0;
		}	
	}
}

void print_record(PERSON data)
{
	printf("�̸� : %s \n", data.name);
	printf("�ּ� : %s \n", data.address);
	printf("�޴��� : %s \n", data.mobilephone);
	printf("Ư¡: %s \n", data.desc);
}

void menu()
{
	printf("====================\n");
	printf(" 1. �߰�\n 2. ����\n 3. �˻�\n 4. ����\n");
	printf("====================\n");
}

void add_record(FILE* fp)
{
	PERSON data;
	printf("�̸�: ");   gets_s(data.name, sizeof(data.name)); 
	printf("�ּ�: ");   gets_s(data.address, sizeof(data.address));  
	printf("�޴��� ��ȣ: ");  gets_s(data.mobilephone, sizeof(data.mobilephone));  
	printf("Ư¡: ");  gets_s(data.desc, sizeof(data.desc));  
	
	fseek(fp, 0, SEEK_END);
	fprintf(fp," %s %s %s %s",data.name,data.address,data.mobilephone,data.desc); 
}

void search_record_a(FILE* fp)
{
	char name[SIZE];
	PERSON data;
	fseek(fp, 0, SEEK_SET);  

	printf("Ž���ϰ��� �ϴ� ����� �̸� : ");
	gets_s(name, 100);
	while (!feof(fp)) 
	{  
		fscanf(fp, "%s %s %s %s", &data.name, &data.address, &data.mobilephone, &data.desc);
		if (strcmp(data.name, name) == 0)  
		{
			printf("�̸�:%s\n ",data.name);   
			printf("�ּ�:%s\n ",data.address);   
			printf("�޴��� ��ȣ:%s\n ",data.mobilephone);  
			printf("Ư¡:%s\n ",data.desc);  
			break;
		}
	}
}

void search_record_b(FILE* fq)
{
	char name[SIZE];
	PERSON data;
	fseek(fq, 0, SEEK_SET);  
	
	printf("Ž���ϰ��� �ϴ� ����� �̸� : ");
	gets_s(name, 100); 
	while (!feof(fq)) 
	{  
		fscanf(fq, "%s %s %s %s", &data.name, &data.address, &data.mobilephone, &data.desc);
		if (strcmp(data.name, name) == 0)
		{
			printf("�̸�:%s\n ", data.name);
			printf("�ּ�:%s\n ", data.address);
			printf("�޴��� ��ȣ:%s\n ", data.mobilephone);
			printf("Ư¡:%s\n ", data.desc);
			break;
		}
	}
}

void update_record(FILE* fp, FILE* fq)
{
	char name[SIZE];
	PERSON data;
	fseek(fp, 0, SEEK_SET);  

	printf("������ �ּ��� ����� �̸� �Է� : ");
	gets_s(name, 100);  
	while (!feof(fp)) 
	{  
		fscanf(fp,"%s %s %s %s",&data.name,&data.address,&data.mobilephone,&data.desc);
		if (strcmp(data.name, name) == 0)  
		{
			printf("�̸�: ");   gets_s(data.name, sizeof(data.name));
			printf("�ּ�: ");   gets_s(data.address, sizeof(data.address));
			printf("�޴��� ��ȣ: ");  gets_s(data.mobilephone, sizeof(data.mobilephone));
			printf("Ư¡: ");  gets_s(data.desc, sizeof(data.desc));
			printf("������ ���� �Ϸ�\n");
			fseek(fq, 0, SEEK_END);
			fprintf(fq," %s %s %s %s",data.name,data.address,data.mobilephone,data.desc);
			break;
		}
	}
}
//20191212