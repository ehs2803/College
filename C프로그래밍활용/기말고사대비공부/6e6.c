#include<stdio.h>

int main(void)
{
	char a[100];
	int i;
	int count = 0;
	int len;
	gets(a);
	len = strlen(a);
	for (i = 0; i < len; i++)
	{
		if (a[i] == 'l')
		{
			if (a[i + 1] == 'o')
			{
				if (a[i + 2] == 'v')
				{
					if (a[i + 3] == 'e')
					{
						count++;
					}
				}
			}
		}
	}
	printf("%d", count);
}
/*
#include <stdio.h>
int main()
{
	char str[101], i;
	int cnt=0;

	fgets(str,101,stdin);
	for(i=0;str[i]!='\0';i++)
		if(str[i]=='l' && str[i+1]=='o' && str[i+2]=='v' && str[i+3]=='e')
			cnt++;

	printf("%d", cnt);
	return 0;
}
*/
//20191118