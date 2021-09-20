#include<stdio.h>

struct music {
	char title[20];
	char singer[20];
	char locate[20];
	int vary;
};

void add();
void print();
void search();

struct music list[10];
int number = 0;

int main(void)
{
	int num;
	char numch[10];

	while (1)
	{
		printf("============================\n");
		printf("  1. 추가\n");
		printf("  2. 출력\n");
		printf("  3. 검색\n");
		printf("  4. 종료\n");
		printf("============================\n");
	AAA:
		printf("정수를 입력하시오: ");
		num = atoi(gets(numch));

		if (num == 1)
		{
			add();
		}
		else if (num == 2)
		{
			print();
		}
		else if (num == 3)
		{
			search();
		}
		else if (num == 4)
		{
			return 0;
		}
		else
		{
			printf("잘못된 숫자입니다. 다시입력하세요.\n");
			goto AAA;
		}
	}

}

void add()
{
	char inadd[10];

	printf("제목: ");
	gets(list[number].title);
	printf("가수: ");
	gets(list[number].singer);
	printf("위치: ");
	gets(list[number].locate);
	printf("장르(0: 가요, 1: 팝, 2: 클래식, 3: 영화음악) ");
	list[number].vary = atoi(gets(inadd));
	number++;
}

void print()
{
	int prinum;
	char prichar[10];

	printf("몇번째 리스트를 검색하시겠습니까? ");
	prinum = atoi(gets(prichar));
	if (prinum > number)
	{
		printf("리스트에 저장된 노래가 없습니다.\n");
		return 0;
	}
	printf("제목:%s \n", list[prinum].title);
	printf("가수:%s \n", list[prinum].singer);
	printf("위치:%s \n", list[prinum].locate);
	if (list[prinum].vary == 0)
	{
		printf("장르: 가요\n");
	}
	else if (list[prinum].vary == 1)
	{
		printf("장르: 팝\n");
	}
	else if (list[prinum].vary == 2)
	{
		printf("장르: 클래식\n");
	}
	else if (list[prinum].vary == 3)
	{
		printf("장르: 영화음악\n");
	}
}

void search()
{
	char searchch[20];
	int i;

	printf("제목을 입력하시오: ");
	gets(searchch);

	for (i = 0; i <= number; i++)
	{
		if (strcmp(searchch, list[i].title) == 0)
		{
			printf("제목:%s \n", list[i].title);
			printf("가수:%s \n", list[i].singer);
			printf("위치:%s \n", list[i].locate);
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
			return 0;
		}
	}
	printf("해당곡을 찾을 수 없습니다.\n");
}
//20191129