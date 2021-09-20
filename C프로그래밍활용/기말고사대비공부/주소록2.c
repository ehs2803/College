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
		fprintf(stderr, "파일을 열 수 없습니다.\n");
		return 0;
	}
	while (1)
	{
		menu();
		printf("항목을 입력:");
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
	printf(" 1. 추가\n");
	printf(" 2. 검색\n");
	printf(" 3. 수정\n");
	printf(" 4. 종료\n");
	printf("=====================\n");
}

void add(FILE* fpp)
{
	PERSON data;

	printf("학번:");
	scanf("%d", &data.num);
	getchar();
	printf("이름:");
	gets_s(data.name, 20);
	printf("전화번호:");
	gets_s(data.phone, 20);

	fseek(fpp, 0, SEEK_END);
	fprintf(fpp, " %d %s %s", data.num, data.name, data.phone);//fprintf(fpp, "%d %s %s ", data.num, data.name, data.phone); 이런식이면
}                                                              //마지막 데이터가 검색 시 두번출력됨

void search(FILE* fpp)
{
	PERSON data;
	char sname[20];

	printf("찾을 이름:");
	scanf("%s", sname);

	fseek(fpp, 0, SEEK_SET);
	while (!feof(fpp))
	{
		fscanf(fpp, "%d %s %s", &data.num, &data.name, &data.phone);
		if (strcmp(data.name, sname) == 0)
		{
			printf("학번:%d\n", data.num);
			printf("이름:%s\n", data.name);
			printf("전화번호:%s\n",data.phone);
		
		}
	}
}

void updata(FILE* fpp)
{
	PERSON data;
	char sname[20];

	printf("수정할 이름:");
	scanf("%s", sname);

	fseek(fpp, 0, SEEK_SET);
	while (!feof(fpp))
	{
		fscanf(fpp, "%d %s %s", &data.num, &data.name, &data.phone);
		if (strcmp(data.name, sname) == 0)
		{
			printf("학번:");
			scanf("%d", &data.num);
			getchar();
			printf("이름:");
			gets_s(data.name, 20);
			printf("전화번호:");
			gets_s(data.phone, 20);
			fseek(fpp, 0, SEEK_SET);
			fprintf(fpp, "%d %s %s\n", data.num, data.name, data.phone);
			return 0;
		}
	}
}
//20191211 + 20191212