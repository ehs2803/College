#include<stdio.h>

int main(void)
{
	char name[100];
	char address[100];

	printf("�̸��� �Է��Ͻÿ�: ");
	scanf_s("%s", name);
	printf("���� �����ϴ� �ּҸ� �Է��Ͻÿ�: ");
	scanf_s("%s", address);

	printf("�̸�: %s\n", name);
	printf("�ּ�: %s\n", address);
}
//20191104