#include<stdio.h>

int main(void)
{
	char str[100];
	char* token;

	int count = 1;
	printf("���ڿ��� �Է��Ͻÿ� : ");
	gets(str);

	token = strtok(str, " ");

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
		{
			count++;
		}
	}
	printf("�ܾ��� �� : %d\n", count);
}
//20191110