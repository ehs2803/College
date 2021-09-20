#include<stdio.h>

int main(void)
{
	int i;
	char a[200];
	gets(a);


	for (i = 0; a[i] != NULL; i++)
	{
		printf("%c", a[i]);
	}

}
//20191118