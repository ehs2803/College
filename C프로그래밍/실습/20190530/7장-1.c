#include<stdio.h>

int main(void)
{
	int a;

	printf("ī������ �ʱⰪ�� �Է��Ͻÿ�: ");
	scanf_s("%d", &a);

	for (a = a; a > 0; a--)
	{
		printf("%d ", a);
	}

	printf("\a");
}