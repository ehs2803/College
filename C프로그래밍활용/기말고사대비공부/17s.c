#include <stdio.h>

int main(void)
{
	char s[100] = { 0 };
	char op[100];
	int x, y;
	char* token;

	printf("������ �Է��Ͻÿ�:");
	gets(s);
	token = strtok(s, " ");	 // ���ڿ����� ù��° ��ū�� ��´�. 
	strcpy(op, token);
	token = strtok(NULL, " "); // ���� ��ū�� ��´�. 
	x = atoi(token);
	token = strtok(NULL, " "); // ���� ��ū�� ��´�. 
	y = atoi(token);

	if (strcmp(op, "add") == 0)
	{
		printf("������ ���: %d \n", x + y);
	}
	else if (strcmp(op, "sub") == 0) 
	{

		if (x > y)
		{
			printf("������ ���: %d \n", x-y);
		}
		else
		{
			printf("������ ���: %d \n", y-x);
		}
	}
	else if (strcmp(op, "mul") == 0) 
	{
		printf("������ ���: %d \n", x * y);
	}
	else if (strcmp(op, "div") == 0)
	{
		if (x > y)
		{
           printf("������ ���: %lf \n", (double)x / y);
		}
		else
		{
			printf("������ ���: %lf \n", (double)y/x);
		}	
	}
}
//20191129