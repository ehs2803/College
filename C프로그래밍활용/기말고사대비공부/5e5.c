#include<stdio.h>

int main(void)
{
	int i;
	char a[100];
	int len;
	int b, c;
	gets(a);
	len = strlen(a);
	b = 0;
	c = 0;
	for (i = 0; i < len; i++)
	{
		if (a[i] == 'C')
		{
			a[i] = a[i] + 32;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (a[i] == 'c')
		{
			b++;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (a[i] == 'c')
		{
			if (a[i + 1] == 'c')
			{
				c++;
			}
		}
	}
	printf("%d\n", b);
	printf("%d", c);
}
//20191118