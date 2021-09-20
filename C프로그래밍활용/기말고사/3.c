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
    printf("정수값을 입력하시오");
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
	printf(" 1. 추가\n");
	printf(" 2. 출력\n");
	printf(" 3. 검색\n");
	printf(" 4. 종료\n");
	printf("==================\n");
}

void add()
{
	printf("도서의 이름:"); gets_s(a[num].title, 20);
	printf("저자:"); gets_s(a[num].name, 20);
	printf("출판사:"); gets_s(a[num].home, 20);
	num++;
}

void print()
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("도서의이름:%s\n", a[i].title);
		printf("저자:%s\n", a[i].name);
		printf("출판사:%s\n", a[i].home);
	}
}

void search()
{
	char sname[20];
	int i;
	printf("검색할 도서이름:"); gets_s(sname, 20);
	for (i = 0; i <= num; i++)
	{
		if (strcmp(sname, a[i].title) == 0)
		{
			printf("도서의이름:%s\n", a[i].title);
			printf("저자:%s\n", a[i].name);
			printf("출판사:%s\n", a[i].home);
			return 0;
		}
	}
	printf("해당도서없음\n");
}