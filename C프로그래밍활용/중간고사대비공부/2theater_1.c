#include<stdio.h>

#define SIZE 10

int main(void)
{
	char ans1;
	int a, i;
	int seats[SIZE] = { 0 };

	for (;;)
	{
		printf("�¼��� �����Ͻðڽ��ϱ�?(y �Ǵ�n) ");
		scanf_s(" %c", &ans1);

		if (ans1 == 'y')
		{
			printf("--------------------------------------\n");
			printf("1  2  3  4  5  6  7  8  9  10\n");
			printf("--------------------------------------\n");

			for (i = 0; i < SIZE; i++)
			{
				printf("%d  ", seats[i]);
			}
			printf("\n");

			printf("���° �¼��� �����Ͻðڽ��ϱ�");
			scanf_s("%d", &a);

			if (seats[a - 1] == 0)
			{
				seats[a - 1] = 1;
				printf("����Ǿ����ϴ�.\n");
			}
			else
			{
				printf("�̹� ����� �ڸ��Դϴ�.\n");
			}
		}
		else
		{
			break;
		}

	}
}
//20191010