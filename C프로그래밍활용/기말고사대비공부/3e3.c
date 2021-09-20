#include <stdio.h>
int main()
{
	char s[200];
	gets(s);//scanf("%s", s);
	if (s[0] == 'l' && s[1] == 'o' && s[2] == 'v' && s[3] == 'e' && s[4] == '\0')
		printf("I love you.");
	return 0;
}
/*
#include<stdio.h>
#include<string.h>

int main(void)
{
	int i;
	char ch[10];
	char in[6]="love";
	scanf("%s",ch);
	if(strcmp(in,ch)==0)
	{
	  printf("I love you.");
	}
}
*/
//20191118