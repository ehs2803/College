#include<stdio.h>

int main(void)
{
	char in[50];
	char ina[10];
	char* inb[10];
	char* word[50];
	int i;
	int count = 0;
	int result;
	char* tok;
	char seq[] = " ";

	printf("���ڿ� : ");
	gets(in);
	printf("ã�� ���ڿ�: ");
	gets(ina);
	

	tok = strtok(in, seq);
	for (i = 0; tok != NULL; i++)
	{
		word[i] = tok;
		tok = strtok(NULL, " ");
		count++;
	}
	for (i = 0; i < count; i++)
	{
		if (strcmp(word[i], ina)==0)
		{
			
			goto AAA;
		}
	}
	printf("ã�� �� �����ϴ�.\n");
	return 0;
AAA:
	printf("�ٲ� ���ڿ�: ");
	gets(inb);
    word[i] = inb;
	for (i = 0; i < count; i++)
	{
		printf("%s ", word[i]);
	}
}//20191121
/*#include<stdio.h>

int main(void)
{
	char in[50];
	char ina[10];
	char inb[10];
	char* word[50];
	int i;
	int count = 0;
	int result;
	char* tok;
	char seq[] = " ";

	printf("���ڿ� : ");
	gets(in);
	printf("ã�� ���ڿ�: ");
	gets(ina);
	printf("�ٲ� ���ڿ�: ");
	gets(inb);

	tok = strtok(in, seq);
	for (i = 0; tok != NULL; i++)
	{
		word[i] = tok;
		tok = strtok(NULL, " ");
		count++;
	}
	for (i = 0; i < count; i++)
	{
		if (strcmp(word[i], ina))
		{
			word[i] = inb;
			goto AAA;
		}
	}
	printf("ã�� �� �����ϴ�.");
AAA:
	for (i = 0; i < count; i++)
	{
		printf("%s", word[i]);
	}
}
//20191120*/