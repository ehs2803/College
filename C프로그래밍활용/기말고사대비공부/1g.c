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
		printf("  1. �߰�\n");
		printf("  2. ���\n");
		printf("  3. �˻�\n");
		printf("  4. ����\n");
		printf("============================\n");
	AAA:
		printf("������ �Է��Ͻÿ�: ");
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
			printf("�߸��� �����Դϴ�. �ٽ��Է��ϼ���.\n");
			goto AAA;
		}
	}

}

void add()
{
	char inadd[10];

	printf("����: ");
	gets(list[number].title);
	printf("����: ");
	gets(list[number].singer);
	printf("��ġ: ");
	gets(list[number].locate);
	printf("�帣(0: ����, 1: ��, 2: Ŭ����, 3: ��ȭ����) ");
	list[number].vary = atoi(gets(inadd));
	number++;
}

void print()
{
	int prinum;
	char prichar[10];

	printf("���° ����Ʈ�� �˻��Ͻðڽ��ϱ�? ");
	prinum = atoi(gets(prichar));
	if (prinum > number)
	{
		printf("����Ʈ�� ����� �뷡�� �����ϴ�.\n");
		return 0;
	}
	printf("����:%s \n", list[prinum].title);
	printf("����:%s \n", list[prinum].singer);
	printf("��ġ:%s \n", list[prinum].locate);
	if (list[prinum].vary == 0)
	{
		printf("�帣: ����\n");
	}
	else if (list[prinum].vary == 1)
	{
		printf("�帣: ��\n");
	}
	else if (list[prinum].vary == 2)
	{
		printf("�帣: Ŭ����\n");
	}
	else if (list[prinum].vary == 3)
	{
		printf("�帣: ��ȭ����\n");
	}
}

void search()
{
	char searchch[20];
	int i;

	printf("������ �Է��Ͻÿ�: ");
	gets(searchch);

	for (i = 0; i <= number; i++)
	{
		if (strcmp(searchch, list[i].title) == 0)
		{
			printf("����:%s \n", list[i].title);
			printf("����:%s \n", list[i].singer);
			printf("��ġ:%s \n", list[i].locate);
			if (list[i].vary == 0)
			{
				printf("�帣: ����\n");
			}
			else if (list[i].vary == 1)
			{
				printf("�帣: ��\n");
			}
			else if (list[i].vary == 2)
			{
				printf("�帣: Ŭ����\n");
			}
			else if (list[i].vary == 3)
			{
				printf("�帣: ��ȭ����\n");
			}
			return 0;
		}
	}
	printf("�ش���� ã�� �� �����ϴ�.\n");
}
//20191129