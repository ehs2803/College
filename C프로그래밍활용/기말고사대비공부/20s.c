#include<stdio.h>

int main(void)
{
	int i, j;
	char an[100];
	char b[100];
	int len;
	gets(an);
	j = 0;
	for (i = 0; an[i] != NULL; i++)
	{
		if (an[i] != ' ')
		{
			b[j] = an[i];
			j++;
		}
	}
	b[j] = '\0';
	for (i = 0; b[i] != '\0'; i++)
	{
		printf("%c", b[i]);
	}


}
/*
#include<stdio.h>
int main() {
	char a[101];
	int i;

	fgets(a, 101, stdin);
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == ' ')
			;
		else
			printf("%c", a[i]);
	}
}
*/
//20191129