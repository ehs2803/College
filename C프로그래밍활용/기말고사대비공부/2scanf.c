#include<stdio.h>

int main(void)
{
	int a, b, c;

	if (scanf_s("%d%d%d", &a, &b, &c) == 3)
	{
		printf("�������� ���� %d\n", a + b + c);
	}
	else
	{
		printf("�Էµ� ���� �ùٸ��� �ʽ��ϴ�\n");
	}
}
//20191128