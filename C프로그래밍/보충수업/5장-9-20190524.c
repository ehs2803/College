#include<stdio.h>

int main(void)
{
	int a, b, c;
	float d;

	printf("�������� ���̸� �Է��Ͻÿ�: ");
	scanf_s("%d", &a);
	printf("������ �׸����� ���̸� �Է��Ͻÿ�: ");
	scanf_s("%d", &b);
	printf("�Ƕ�̵������ �Ÿ��� �Է��Ͻÿ�: ");
	scanf_s("%d", &c);

	d = a * c / b;

	printf("�Ƕ�̵��� ���̴� %f�Դϴ�. ",d);
	
}