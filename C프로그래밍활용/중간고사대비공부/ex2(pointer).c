#include<stdio.h>

int main(void)
{
	int num1 = 10;
	int num2 = 20;
	int temp;

	int* ptr1 = &num1;
	int* ptr2 = &num2;

	*ptr1 = *ptr1 + 10;
	*ptr2 = *ptr2 - 10;

	printf("��ȯ���� ptr1 = %d, ��ȯ���� ptr2 = %d\n", *ptr1, *ptr2);

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;

	printf("��ȯ���� ptr1 = %d, ��ȯ���� ptr2 = %d", *ptr1, *ptr2);

}
//20191025