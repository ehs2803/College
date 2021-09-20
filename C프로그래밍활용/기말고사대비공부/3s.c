#include<stdio.h>
#include<ctype.h>

int main(void)
{
	int c;

	while ((c = getchar()) != '.')
	{
		if (islower(c))
		{
			c = toupper(c);
		}
		putchar(c);
	}
}
//20191129