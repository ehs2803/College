#include<stdio.h>


int main(void)
{
	char s[] = "Man is immortal, because he has a soul";
	char seps[] = " ,\t\n";
	char* tok;

	tok = strtok(s, seps);

	while (tok != NULL)
	{

		printf("ÅäÅ«: %s\n", tok);
		tok = strtok(NULL, seps);
	}
}
//20191129