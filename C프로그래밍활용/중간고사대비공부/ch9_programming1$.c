#include<stdio.h>

int main(void)
{
	static int count1, count2, count3, count4=0;
	int input1, input2;
	char op;
	int result;

	for (;;)
	{
		printf("������ �Է��Ͻÿ�: ");
		scanf_s("%d %c %d", &input1, &op, &input2);
		if (op=='+')
		{
			count1++;
			result = input1 + input2;
			printf("������ �� %d�� ����Ǿ����ϴ�.",count1);
		    printf("���� ���: %d",result);
		}
		else if (op=='-')
		{
			count2++;
			printf("������ �� %d�� ����Ǿ����ϴ�.",count2);
			printf("���� ���: %d", result);
		}
		else if (op == '*')
		{
			count3++;
			printf("������ �� %d�� ����Ǿ����ϴ�.",count3);
			printf("���� ���: %d", result);
		}
		else if (op == '/')
		{
			count4++;
			printf("�������� �� %d�� ����Ǿ����ϴ�.",count4);
			printf("���� ���: %d", result);
		}
	

	}
}
/*
#include <stdio.h>

int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main(void)
{
	char op;
	int x, y;
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("������ �Է��Ͻÿ�: ");
		scanf_s("%d %c %d", &x, &op, &y);
		if (op == '+')
			printf("���� ���: %d \n", add(x, y));
		else if (op == '-')
			printf("���� ���: %d \n", sub(x, y));
		else if (op == '*')
			printf("���� ���: %d \n", mul(x, y));
		else if (op == '/')
			printf("���� ���: %d \n", div(x, y));
		else
			printf("�������� �ʴ� �������Դϴ�. \n");
	}
	return 0;
}
int add(int x, int y)
{
	static int count;
	count++;
	printf("������ �� %d�� ����Ǿ����ϴ�.\n", count);
	return (x + y);
}

int sub(int x, int y)
{
	static int count;
	count++;
	printf("������ �� %d�� ����Ǿ����ϴ�.\n", count);
	return (x - y);
}
int mul(int x, int y)
{
	static int count;
	count++;
	printf("������ �� %d�� ����Ǿ����ϴ�.\n", count);
	return (x * y);
}
int div(int x, int y)
{
	static int count;
	count++;
	printf("�������� �� %d�� ����Ǿ����ϴ�.\n", count);
	return (x / y);
}
*/
