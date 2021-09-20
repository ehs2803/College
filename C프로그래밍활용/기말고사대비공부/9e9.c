#include<stdio.h>
#include<string.h>

int main(void)
{
	char a[20];
	char b[20];
	char c[20];
	int lena, lenb, lenc;
	gets(a);//scanf("%s", a);
	gets(b);//scanf("%s", b);
	gets(c);//scanf("%s", c);
	lena = strlen(a);
	lenb = strlen(b);
	lenc = strlen(c);
	if ((a[0] == c[lenc - 1]) && (a[lena - 1] == b[0]) && (b[lenb - 1] == c[0]))
	{
		printf("good");
	}
	else
	{
		printf("bad");
	}

}
//20191118