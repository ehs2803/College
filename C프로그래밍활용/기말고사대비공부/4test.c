#define _NO_SECURE_NO_WARNING
#include<stdio.h>

struct student {
	int age;
	char name[10];
}a;

int main(void)
{
	char search[10];
	int i;

	
		printf("���̸� �Է��Ͻÿ�: ");
		scanf("%d", &a.age);

		printf("�̸��� �Է��Ͻÿ�: ");
		scanf("%s", a.name);
	
	printf("ã�� �̸�: ");
	scanf("%s", search);
	for (i = 0; a.name[i]!=NULL; i++)
	{
		if (a.name[i] == search[i])
		{

		}
		else
		{
			printf("�ٸ���");
			return 0;
		}
	}
	printf("����");
}
//20191127