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
//20191106