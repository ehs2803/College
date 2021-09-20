#include<stdio.h>

typedef struct person {
	int num;
	char name[20];
	char phone[20];
	char address[20];
}PERSON;

void menu();
void add();
void update();
void search();

PERSON a[20];
int number = 0;

int main(void)
{
	int num;

	while (1)
	{
		menu();
		printf("항목을 선택하시오:");
	    scanf("%d", &num); //getchar();
		if (num == 1)
		{
			add();
		}
		else if (num == 2)
		{
			update();
		}
		else if (num == 3)
		{
			search();
		}
		else if (num == 4)
		{
			return 0;
		}
	}
}

void menu()
{
	printf("========================\n");
	printf(" 1. 추가\n");
	printf(" 2. 수정\n");
	printf(" 3. 검색\n");
	printf(" 4. 종료\n");
	printf("========================\n");
}

void add()
{
	printf("번호:"); scanf("%d", &a[number].num);
	printf("이름:"); scanf("%s", a[number].name);
	printf("전화번호:"); scanf("%s", a[number].phone);
	printf("주소:"); scanf("%s", a[number].address);
	number++;
}

void update()
{
	int i;
	char sname[20];
	printf("수정할 이름입력:"); scanf("%s", sname);
	for (i = 0;i <= number; i++)
	{
		if (strcmp(a[i].name, sname) == 0)
		{
			printf("번호:"); scanf("%d", &a[i].num);
			printf("이름:"); scanf("%s", a[i].name);
			printf("전화번호:"); scanf("%s", a[i].phone);
			printf("주소:"); scanf("%s", a[i].address);
		}
	}
}

void search()
{
	int i;
	char sname[20];
	printf("검색할 이름입력:"); scanf("%s", sname);
	for (i = 0; i <= number; i++)
	{
		if (strcmp(a[i].name, sname) == 0)
		{
			printf("번호:%d\n",a[i].num);
			printf("이름:%s\n", a[i].name); 
			printf("전화번호:%s\n",a[i].phone); 
			printf("주소:%s\n", a[i].address); 
		}
	}
}
//20191214