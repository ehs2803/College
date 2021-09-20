#include<stdio.h>

int main(void)
{
	static int count1, count2, count3, count4=0;
	int input1, input2;
	char op;
	int result;

	for (;;)
	{
		printf("연산을 입력하시오: ");
		scanf_s("%d %c %d", &input1, &op, &input2);
		if (op=='+')
		{
			count1++;
			result = input1 + input2;
			printf("덧셈은 총 %d번 실행되었습니다.",count1);
		    printf("연산 결과: %d",result);
		}
		else if (op=='-')
		{
			count2++;
			printf("뺄셈은 총 %d번 실행되었습니다.",count2);
			printf("연산 결과: %d", result);
		}
		else if (op == '*')
		{
			count3++;
			printf("곱셈은 총 %d번 실행되었습니다.",count3);
			printf("연산 결과: %d", result);
		}
		else if (op == '/')
		{
			count4++;
			printf("나눗셈은 총 %d번 실행되었습니다.",count4);
			printf("연산 결과: %d", result);
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
		printf("연산을 입력하시오: ");
		scanf_s("%d %c %d", &x, &op, &y);
		if (op == '+')
			printf("연산 결과: %d \n", add(x, y));
		else if (op == '-')
			printf("연산 결과: %d \n", sub(x, y));
		else if (op == '*')
			printf("연산 결과: %d \n", mul(x, y));
		else if (op == '/')
			printf("연산 결과: %d \n", div(x, y));
		else
			printf("지원되지 않는 연산자입니다. \n");
	}
	return 0;
}
int add(int x, int y)
{
	static int count;
	count++;
	printf("덧셈은 총 %d번 실행되었습니다.\n", count);
	return (x + y);
}

int sub(int x, int y)
{
	static int count;
	count++;
	printf("뺄셈은 총 %d번 실행되었습니다.\n", count);
	return (x - y);
}
int mul(int x, int y)
{
	static int count;
	count++;
	printf("곱셈은 총 %d번 실행되었습니다.\n", count);
	return (x * y);
}
int div(int x, int y)
{
	static int count;
	count++;
	printf("나눗셈은 총 %d번 실행되었습니다.\n", count);
	return (x / y);
}
*/
