#include<stdio.h>

int sum(int input1);
int result;

int main(void)
{   
	
	static int input;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &input);
	sum(input);
	printf("1���� 10������ ��=%d", result);
}

int sum(int input1)
{
	if (input1 >=1)
	{
		result = result + input1;
		input1 = input1 - 1;
		sum(input1);
	}
	
}



/*
#include <stdio.h>
int sum(int n);

int main()
{
	int number, result;

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &number);

	result = sum(number);

	printf("1���� %d������ ��=%d\n", number, result);
}

int sum(int num)
{
	if (num != 0)
		return num + sum(num - 1);
	else
		return num;
}
*/