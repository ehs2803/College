#include<stdio.h>

int main(void)
{
	char name[20];
	char seq[] = " ";
	char* tok;
	char* word[3];
	int i;
	int count = 0;

	printf("�̸��� �Է��ϼ���(�빮�ڷ�): ");
	gets(name);

	for (i = 0; name[i] != '\0'; i++)
	{
		if ('A' <= name[i] && name[i] <= 'Z')
		{
			name[i] = name[i] + 32;
		}
	}

	tok = strtok(name, seq);
	for (i = 0; tok != NULL; i++)
	{
		word[i] = tok;
		tok = strtok(NULL, " ");
		count++;
	}

	
		printf("%s", word[1]);
		printf(", ");
		printf("%s", word[0]);
	
}//20191121
/*#include<stdio.h>

int main(void)
{
	char name[20];
	char seq[] = " ";
	char* tok;
	char* word[3];
	int i;
	int count = 0;

	printf("�̸��� �Է��ϼ���(�빮�ڷ�): ");
	gets(name);

	for (i = 0; name[i] != '\0'; i++)
	{
		if ('A' <= name[i] && name[i] <= 'Z')
		{
			name[i] = name[i] + 32;
		}
	}

	tok = strtok(name, seq);
	for (i = 0; tok != NULL; i++)
	{
		word[i] = tok;
		tok = strtok(NULL, " ");
		count++;
	}
	
	for (i = 0; i < count; i++)
	{
		printf("%s", word[count - i - 1]);
		printf(", ");
	}
}
/20191120+�����ʿ�*/