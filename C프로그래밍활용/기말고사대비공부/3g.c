#include<stdio.h>
#include<string.h>

typedef struct {
	char name[10];
	char phone_num[10];
	char home_num[10];
} phone_info;

int main(void)
{
	phone_info info[3];
	char search[10];
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("�̸� : ");
		gets(info[i].name);//scanf_s("%s",info[i].name,10);
		printf("�޴���ȭ ��ȣ : ");
		gets(info[i].phone_num);
		printf("�� ��ȭ ��ȣ : ");
		gets(info[i].home_num);
	}
	printf("ã�� �̸� : ");
	gets(search);
	for (i = 0; i < 3; i++)
	{
		if (strcmp(info[i].name, search) == 0)
		{
			printf("�޴���ȭ ��ȣ : %s\n", info[i].phone_num);
			printf("�� ��ȭ ��ȣ: %s\n", info[i].home_num);
			return 0;
		}
	}
	printf("����\n");
	return 0;
}
//20191129