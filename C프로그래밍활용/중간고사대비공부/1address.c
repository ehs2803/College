#include<stdio.h>

int main(void)
{
	int i = 10;
	char c = 69;
	double f = 12.3;

	int* a;
	int* b;
	int* d;

	a = &i;
	b = &c;
	d = &f;

	printf("i�� �ּ�: %u %u\n", &i,a);
	printf("c�� �ּ�: %u %u\n", &c,b);
	printf("f�� �ּ�: %u %u\n", &f,d);

	printf("%d", *a);//���� ���� ������
	
}
//20191010