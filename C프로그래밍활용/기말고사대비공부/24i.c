#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void mnun();
void add(FILE* fpp);

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
		fprintf(stderr, "파일을 열 수 없습니다.\n");
		exit(1);
	}
	while (1)
	{
		mnun();
		printf("몇번을 선택하시겠습니까? ");
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
	printf(" 1. 추가\n");
	printf(" 2. 출력\n");
	printf(" 3. 검색\n");
	printf(" 4. 종료\n");
	printf("====================\n");
}

void add(FILE* fpp)
{
	PERSON data;

	printf("이름:");
	gets_s(data.name, 10);
	printf("전화번호:");
	gets_s(data.phone, 15);
	printf("주소:");
	gets_s(data.adderss, 20);
	printf("특징");
	gets_s(data.feature, 20);

	fseek(fpp, 0, SEEK_END);
	fprintf(fpp,"%s %s %s %s\n", data.name, data.phone, data.adderss, data.feature);
}
