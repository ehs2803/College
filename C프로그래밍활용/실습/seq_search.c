#include<stdio.h>
#define size 10

int main(void)
{
	int key, i;
	int list[size] = { 1,2,3,4,5,6,7,8,9 };

	printf("Ž���� ���� �Է��Ͻÿ�:");
	scanf_s("%d", &key);

	for (i = 0; i < size; i++)
	{
		if (list[i] == key)
		{
			printf("Ž�� ���� �ε���= %d\n", i);
		}
	}
	printf("Ž�� ����\n");
}