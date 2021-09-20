#include<stdio.h>

typedef struct music{
	char name[20];
    char singer[20];
	char locate[20];
	int vary;
}MUSIC;

void num1();
void num2();
void num3();

int number=0;
MUSIC list[100];
int main(void)
{
	

	while (1)
	{
		int i;
		printf("======================\n");
		printf(" 1. 추가\n");
		printf(" 2. 출력\n");
		printf(" 3. 검색\n");
		printf(" 4. 종료\n");
		printf("======================\n");
		printf("정수값을 입력하시오: ");
		scanf_s("%d", &i);
		if (i == 1)
		{
			num1();
		}
		else if (i == 2)
		{
			num2();
		}
		else if (i == 3)
		{
			num3();
		}
		else if (i == 4)
		{
			return 0;
		}
	}
}

void num1()
{
	printf("제목:");
	gets(list[number].name);
	printf("가수: ");
	gets(list[number].singer);
	printf("위치: ");
	gets(list[number].locate);
	printf("장르(0: 가요, 1: 팝, 2: 클래식, 3: 영화음악)");
	scanf_s("%d", &list[number].vary);
	number++;
}

void num2()
{
	int a;
AAA:
	printf("리스트 몇번을 출력할까요? ");
	scanf_s("%d", &a);
	if (number > a)
	{
		printf("존재하지 않습니다.");
		goto AAA;
	}
	printf("제목: %s\n", list[a].name);
	printf("가수: %s\n", list[a].singer);
	printf("위치: %s\n", list[a].locate);
	if (list[a].vary == 0)
	{
		printf("장르: 가요\n");
	}
	else if (list[a].vary == 1)
	{
		printf("장르: 팝\n");
	}
	else if (list[a].vary == 2)
	{
		printf("장르: 클래식\n");
	}
	else if (list[a].vary == 3)
	{
		printf("장르: 영화음악\n");
	}
	
}

void num3()
{
	int i;
	char search[20];
	printf("검색할 노래 제목을 입력하시오: ");
	gets(search);
	for (i = 0; i <= number; i++)
	{
		if (strcmp(list[i].name, search) == 0)
		{
			printf("제목: %s\n", list[i].name);
			printf("가수: %s\n", list[i].singer);
			printf("위치: %s\n", list[i].locate);
			if (list[i].vary == 0)
			{
				printf("장르: 가요\n");
			}
			else if (list[i].vary == 1)
			{
				printf("장르: 팝\n");
			}
			else if (list[i].vary == 2)
			{
				printf("장르: 클래식\n");
			}
			else if (list[i].vary == 3)
			{
				printf("장르: 영화음악\n");
			}
		}
	}
}
//20191122+수정