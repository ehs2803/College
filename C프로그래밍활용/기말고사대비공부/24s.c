#include<stdio.h>
#include<string.h>

int main(void)
{
	char a[200];
	char b[200];
	int lena;
	int lenb;
	int i;
	scanf("%s", a);
	scanf("%s", b);
	lena = strlen(a);
	lenb = strlen(b);
	if (lena > lenb)
	{
		printf("%s %s", b, a);
		return 0;
	}
	else if (lena < lenb)
	{
		printf("%s %s", a, b);
		return 0;
	}
	for (i = 0; a[i] != NULL; i++)
	{
		if (a[i] > b[i])
		{
			printf("%s %s", b, a);
			return 0;
		}
		else if (a[i] < b[i])
		{
			printf("%s %s", a, b);
			return 0;
		}
	}
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	int l1, l2;
	char str1[101], str2[101];
	int i;

	scanf("%s %s", str1, str2);
	l1 = strlen(str1);
	l2 = strlen(str2);

	if (l1 > l2)
		printf("%s %s", str2, str1);
	else if (l1 < l2)
		printf("%s %s", str1, str2);
	else {
		for(i = 0; i < l2; i++)
			if (str1[i] > str2[i]) {
				printf("%s %s", str2, str1);
				return 0;
			}
			else if (str1[i] < str2[i]) {
				printf("%s %s", str1, str2);
				return 0;
			}
			else ;
	}
	return 0;
}
*/
//20191129