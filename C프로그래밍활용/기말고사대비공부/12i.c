#include <stdio.h>
#include <string.h>
#define TITLE_SIZE 50
#define NAME_SIZE 50
#define PUBLISHER_SIZE 50

typedef struct BOOK {
	char title[TITLE_SIZE];
	char author[NAME_SIZE];
	char publisher[PUBLISHER_SIZE];
} BOOK;

void add_record(BOOK library[], int count);
void menu();
int get_input();
void search_record(BOOK library[], int count);
void print_record(BOOK library[], int count);
int main(void)
{
	int num, count = 0;
	BOOK library[30] = { '\0' };
	while (1)
	{
		menu();
		num = get_input();
		if (num == 1)
		{
			add_record(library, count);
			count++;
		}
		else if (num == 2)
		{
			print_record(library, count);
		}
		else if (num == 3)
		{
			search_record(library, count);
		}
		else if (num == 4)
		{
			return 0;
		}			
	}
}
void add_record(BOOK library[], int count)
{
	printf("������ �̸�:");
	gets(library[count].title);
	printf("����:");
	gets(library[count].author);
	printf("���ǻ�:");
	gets(library[count].publisher);
}
void menu()
{
	printf("====================\n");
	printf(" 1. �߰�\n");
	printf(" 2. ���\n");
	printf(" 3. �˻�\n");
	printf(" 4. ����\n");
	printf("====================\n");
}
int get_input()
{
	int num;
	printf("�������� �Է��Ͻÿ� : ");
	scanf("%d", &num);
	getchar();
	return num;
}
void search_record(BOOK library[], int count)
{
	int i;
	char title[TITLE_SIZE];

	printf("����: ");
	gets(title);

	for (i = 0; i < count; i++)
	{
		if (strcmp(title, library[i].title) == 0)
		{
			printf("���ǻ�� %s\n", library[i].publisher);
			return;
		}
	}
	printf("ã�� å�� ���̺� �����ϴ�.\n");
}
void print_record(BOOK library[], int count)
{
	int i;
	
	for (i = 0; i < count; i++)
	{
		printf("���� : %s\n", library[i].title);
		printf("���� : %s\n", library[i].author);
		printf("���ǻ� : %s\n", library[i].publisher);
	}
}
//20191130 success