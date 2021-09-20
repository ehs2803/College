#define _CRT_SECURE_NO_WARNING
#include<stdio.h>

int main(void)
{
	char in[30];
	int i;
	int a, b;
	a = 0;
	b = 0;
	gets(in);
	for (i = 0; in[i] != 0; i++)
	{
		if (in[i] == '(')
		{
			a++;
		}
		else if (in[i] == ')')
		{
			b++;
		}
	}
	printf("%d %d", a,b);
}
//20191127