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
		printf("�׸��� �����Ͻÿ�:");
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
	printf(" 1. �߰�\n");
	printf(" 2. ����\n");
	printf(" 3. �˻�\n");
	printf(" 4. ����\n");
	printf("========================\n");
}

void add()
{
	printf("��ȣ:"); scanf("%d", &a[number].num);
	printf("�̸�:"); scanf("%s", a[number].name);
	printf("��ȭ��ȣ:"); scanf("%s", a[number].phone);
	printf("�ּ�:"); scanf("%s", a[number].address);
	number++;
}

void update()
{
	int i;
	char sname[20];
	printf("������ �̸��Է�:"); scanf("%s", sname);
	for (i = 0;i <= number; i++)
	{
		if (strcmp(a[i].name, sname) == 0)
		{
			printf("��ȣ:"); scanf("%d", &a[i].num);
			printf("�̸�:"); scanf("%s", a[i].name);
			printf("��ȭ��ȣ:"); scanf("%s", a[i].phone);
			printf("�ּ�:"); scanf("%s", a[i].address);
		}
	}
}

void search()
{
	int i;
	char sname[20];
	printf("�˻��� �̸��Է�:"); scanf("%s", sname);
	for (i = 0; i <= number; i++)
	{
		if (strcmp(a[i].name, sname) == 0)
		{
			printf("��ȣ:%d\n",a[i].num);
			printf("�̸�:%s\n", a[i].name); 
			printf("��ȭ��ȣ:%s\n",a[i].phone); 
			printf("�ּ�:%s\n", a[i].address); 
		}
	}
}
//20191214