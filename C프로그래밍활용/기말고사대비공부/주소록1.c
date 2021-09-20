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
		fprintf(stderr, "파일을 열 수 없음.\n");
		exit(1);
	}
	while (1)
	{
		menu();
		printf("항목을 선택하세요:");
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
	printf(" 1. 추가\n");
	printf(" 2. 수정\n");
	printf(" 3. 검색\n");
	printf(" 4. 종료\n");
	printf("==========================\n");
}

void add(FILE* fpp)
{
	PERSON data;
	printf("이름:");
	gets_s(data.name, 20);
	printf("전화번호:");
	gets_s(data.phone, 20);
	printf("주소:");
	gets_s(data.address, 20);
	printf("특징:");
	gets_s(data.feature, 20);
	fseek(fpp, 0, SEEK_END);
	fwrite(&data, sizeof(data), 1, fpp);

}

void search(FILE* fpp)
{
	PERSON data;
	char sname[20];
	printf("찾을 이름을 적으세요:");
	gets_s(sname, 20);
	fseek(fpp, 0, SEEK_SET);
	while (!feof(fpp))
	{
		fread(&data, sizeof(data), 1, fpp);
		if (strcmp(data.name, sname) == 0)
		{
			printf("전화번호:%s\n", data.phone);
			printf("주소:%s\n", data.address);
			printf("특징:%s\n", data.feature);
			return 0;
		}
	}
	printf("찾을 수 없습니다.\n");
}
//20191207