#include<stdio.h>

int main(void)
{
	char a;
	int b;

	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%c", &a);
	printf("�ƽ�Ű �ڵ� : %d\n", a);

	printf("�ƽ�Ű �ڵ� ���� �Է� : ");
	scanf_s("%d", &b);
	printf("���ڴ� : %c", b);
}