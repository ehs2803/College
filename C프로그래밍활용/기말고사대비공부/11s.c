#include<stdio.h>

int main(void)
{
	char str[80];
	char* word[80];//�������迭char word[100][80];�̸� ������.
	char* token;
	int i, count = 0;

	printf("���ڿ��� �Է��Ͻÿ� : ");
	gets_s(str, 80);//gets(str);

	token = strtok(str, " ");

	for (i = 0; token != NULL; i++)
	{
		word[i] = token;
		token = strtok(NULL, " ");
		count++;
	}
	printf("��� ���ڿ� :");
	for (i = 0; i < count; i++)
	{
		printf("%s ", word[count - i - 1]);
	}
}
//20191129