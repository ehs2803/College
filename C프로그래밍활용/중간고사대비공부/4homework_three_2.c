#include <stdio.h>

int main(void)
{
	int list[3][10] = { 0 };
	int input, i;

	for (i = 0; i < 10; i++)
	{
		list[0][i] = i;
		list[1][i] = i * i;
		list[2][i] = i * i * i;
	}

	printf("������ �Է��Ͻÿ�:");
	scanf_s("%d", &input);

	for (i = 0; i < 10; i++)
	{
		if (input == list[2][i])
		{
			printf("%d�� ���������� %d\n", input, i);
		}
	}
}
//20191017 chpater10_7