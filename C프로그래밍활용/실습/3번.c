#include<stdio.h>

int str_chr(char* string, char find_alpha);

int main(void)
{
	char str[80];
	char find;
	int count;

	printf("���ڿ��� �Է��Ͻÿ� ");
	gets(str);

	printf("������ �� ���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%c", &find);

	printf("������ ���� : %d", str_chr(str, find));

}

int str_chr(char* string, char find_alpha)
{
	int i = 0;
	int count = 0;
	for (i = 0; string[i] != NULL;i++)
	{
		if (string[i] == find_alpha)
		{
			count++;
		}
	}
	return count;
}