#include<stdio.h>

struct phone {
	char name[10];
	char home[10];
	char cell[10];
};

int main(void)
{
	struct phone s[3];

	int i, j;

	char find[10];

	for (i = 0; i < 3; i++)
	{
		printf("�̸��� �Է��Ͻÿ�: ");
		gets(s[i].name);

		printf("����ȭ��ȣ�� �Է��Ͻÿ�: ");
		gets(s[i].home);

		printf("�޴�����ȣ�� �Է��Ͻÿ�: ");
		gets(s[i].cell);
	}

	printf("�̸��� �Է��Ͻÿ�: ");
	gets(find);

	for (i = 0; i < 3; i++)
	{
		if (strcmp(s[i].name, find) == 0)
		{
			j = i;
		}
	}

	printf("�̸�:%s\n",s[j].name);
	printf("����ȭ��ȣ: %s\n",s[j].home);
	printf("�޴�����ȣ: %s\n",s[j].cell);
}