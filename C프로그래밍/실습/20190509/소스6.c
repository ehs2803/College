#include<stdio.h>

int main(void)
{

	int n;
	int i;
	int sum=0;

	

	for (i = 1; i <= 5; i++)
	{
		printf("���� �Է��Ͻÿ�");
		scanf_s("%d", &n);
		sum = sum +n;

	}

	printf("�հ�� %d�Դϴ�.", sum);

}