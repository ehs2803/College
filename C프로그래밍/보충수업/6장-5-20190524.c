#include<stdio.h>

int main(void)
{
	int a, b;

	printf("Ű�� �Է��Ͻÿ�(cm): ");
	scanf_s("%d", &a);
	printf("���̸� �Է��Ͻÿ�: ");
	scanf_s("%d", &b);

	if (a >= 140 && b >= 10)
	{
		printf("Ÿ�� �����ϴ�");
	}
	else
	{
		printf("�˼��մϴ�");
	}
}