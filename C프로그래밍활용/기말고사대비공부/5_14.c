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
		printf(" 1. �߰�\n");
		printf(" 2. ���\n");
		printf(" 3. �˻�\n");
		printf(" 4. ����\n");
		printf("======================\n");
		printf("�������� �Է��Ͻÿ�: ");
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
	printf("����:");
	gets(list[number].name);
	printf("����: ");
	gets(list[number].singer);
	printf("��ġ: ");
	gets(list[number].locate);
	printf("�帣(0: ����, 1: ��, 2: Ŭ����, 3: ��ȭ����)");
	scanf_s("%d", &list[number].vary);
	number++;
}

void num2()
{
	int a;
AAA:
	printf("����Ʈ ����� ����ұ��? ");
	scanf_s("%d", &a);
	if (number > a)
	{
		printf("�������� �ʽ��ϴ�.");
		goto AAA;
	}
	printf("����: %s\n", list[a].name);
	printf("����: %s\n", list[a].singer);
	printf("��ġ: %s\n", list[a].locate);
	if (list[a].vary == 0)
	{
		printf("�帣: ����\n");
	}
	else if (list[a].vary == 1)
	{
		printf("�帣: ��\n");
	}
	else if (list[a].vary == 2)
	{
		printf("�帣: Ŭ����\n");
	}
	else if (list[a].vary == 3)
	{
		printf("�帣: ��ȭ����\n");
	}
	
}

void num3()
{
	int i;
	char search[20];
	printf("�˻��� �뷡 ������ �Է��Ͻÿ�: ");
	gets(search);
	for (i = 0; i <= number; i++)
	{
		if (strcmp(list[i].name, search) == 0)
		{
			printf("����: %s\n", list[i].name);
			printf("����: %s\n", list[i].singer);
			printf("��ġ: %s\n", list[i].locate);
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
		}
	}
}
//20191122+����