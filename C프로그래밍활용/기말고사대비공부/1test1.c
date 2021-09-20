#include<stdio.h>
#include<ctype.h>

int main(void)
{
	char in[20];
	int i;
	int count = 1;

	gets(in);
	printf("%s\n", in);

	for (i = 0; in[i] != '\0'; i++)
	{
		printf("%c", in[i]);
	}
	printf("\n");
	for (i = 0; in[i] != '\0'; i++)
	{
		if (isspace(in[i]))
		{
			count++;
		}
	}

	printf("단어 개수 : %d", count);

}
//20191120