#include <stdio.h>

int main(void)
{
	char s[100] = { 0 };
	char op[100];
	int x, y;
	char* token;

	printf("연산을 입력하시오:");
	gets(s);
	token = strtok(s, " ");	 // 문자열에서 첫번째 토큰을 얻는다. 
	strcpy(op, token);
	token = strtok(NULL, " "); // 다음 토큰을 얻는다. 
	x = atoi(token);
	token = strtok(NULL, " "); // 다음 토큰을 얻는다. 
	y = atoi(token);

	if (strcmp(op, "add") == 0)
	{
		printf("연산의 결과: %d \n", x + y);
	}
	else if (strcmp(op, "sub") == 0) 
	{

		if (x > y)
		{
			printf("연산의 결과: %d \n", x-y);
		}
		else
		{
			printf("연산의 결과: %d \n", y-x);
		}
	}
	else if (strcmp(op, "mul") == 0) 
	{
		printf("연산의 결과: %d \n", x * y);
	}
	else if (strcmp(op, "div") == 0)
	{
		if (x > y)
		{
           printf("연산의 결과: %lf \n", (double)x / y);
		}
		else
		{
			printf("연산의 결과: %lf \n", (double)y/x);
		}	
	}
}
//20191129