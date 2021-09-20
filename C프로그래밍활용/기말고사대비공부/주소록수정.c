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
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다");
		exit(1);
	}
	while (1)
	{
		menu();  
		printf("메뉴를 선택하세요: ");  
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
			printf("1. 수정 전, 2. 수정 후 : ");
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
	printf("이름 : %s \n", data.name);
	printf("주소 : %s \n", data.address);
	printf("휴대폰 : %s \n", data.mobilephone);
	printf("특징: %s \n", data.desc);
}

void menu()
{
	printf("====================\n");
	printf(" 1. 추가\n 2. 수정\n 3. 검색\n 4. 종료\n");
	printf("====================\n");
}

void add_record(FILE* fp)
{
	PERSON data;
	printf("이름: ");   gets_s(data.name, sizeof(data.name)); 
	printf("주소: ");   gets_s(data.address, sizeof(data.address));  
	printf("휴대폰 번호: ");  gets_s(data.mobilephone, sizeof(data.mobilephone));  
	printf("특징: ");  gets_s(data.desc, sizeof(data.desc));  
	
	fseek(fp, 0, SEEK_END);
	fprintf(fp," %s %s %s %s",data.name,data.address,data.mobilephone,data.desc); 
}

void search_record_a(FILE* fp)
{
	char name[SIZE];
	PERSON data;
	fseek(fp, 0, SEEK_SET);  

	printf("탐색하고자 하는 사람의 이름 : ");
	gets_s(name, 100);
	while (!feof(fp)) 
	{  
		fscanf(fp, "%s %s %s %s", &data.name, &data.address, &data.mobilephone, &data.desc);
		if (strcmp(data.name, name) == 0)  
		{
			printf("이름:%s\n ",data.name);   
			printf("주소:%s\n ",data.address);   
			printf("휴대폰 번호:%s\n ",data.mobilephone);  
			printf("특징:%s\n ",data.desc);  
			break;
		}
	}
}

void search_record_b(FILE* fq)
{
	char name[SIZE];
	PERSON data;
	fseek(fq, 0, SEEK_SET);  
	
	printf("탐색하고자 하는 사람의 이름 : ");
	gets_s(name, 100); 
	while (!feof(fq)) 
	{  
		fscanf(fq, "%s %s %s %s", &data.name, &data.address, &data.mobilephone, &data.desc);
		if (strcmp(data.name, name) == 0)
		{
			printf("이름:%s\n ", data.name);
			printf("주소:%s\n ", data.address);
			printf("휴대폰 번호:%s\n ", data.mobilephone);
			printf("특징:%s\n ", data.desc);
			break;
		}
	}
}

void update_record(FILE* fp, FILE* fq)
{
	char name[SIZE];
	PERSON data;
	fseek(fp, 0, SEEK_SET);  

	printf("수정할 주소의 사람의 이름 입력 : ");
	gets_s(name, 100);  
	while (!feof(fp)) 
	{  
		fscanf(fp,"%s %s %s %s",&data.name,&data.address,&data.mobilephone,&data.desc);
		if (strcmp(data.name, name) == 0)  
		{
			printf("이름: ");   gets_s(data.name, sizeof(data.name));
			printf("주소: ");   gets_s(data.address, sizeof(data.address));
			printf("휴대폰 번호: ");  gets_s(data.mobilephone, sizeof(data.mobilephone));
			printf("특징: ");  gets_s(data.desc, sizeof(data.desc));
			printf("데이터 수정 완료\n");
			fseek(fq, 0, SEEK_END);
			fprintf(fq," %s %s %s %s",data.name,data.address,data.mobilephone,data.desc);
			break;
		}
	}
}
//20191212