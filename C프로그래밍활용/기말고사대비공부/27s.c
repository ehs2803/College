#include<stdio.h>
#include<ctype.h>

int main(void)
{
	int c;
	printf("input number : ");
	c = getchar();

	if (isalpha(c))
	{
		if (islower(c))
		{
			c = toupper(c);
			putchar(c);
			printf("\n");
		}
		else if (isupper(c))
		{
			c = tolower(c);
			putchar(c);
			printf("\n");
		}
	}
	else
	{
		printf("error number\n");
	}
}
/*
#include<stdio.h>

int main(void)
{
	int c;
	printf("input number : ");
	c = getchar();

	if (('A' <= c) && (c <= 'z'))
	{
		if (('a' <= c) && (c <= 'z'))
		{
			c = c - 32;
			putchar(c);
			printf("\n");
		}
		else if (('A' <= c) && (c <= 'Z'))
		{
			c = c + 32;
			putchar(c);
			printf("\n");
		}
	}
	else
	{
		printf("error number\n");
	}
}
*/
//20191129