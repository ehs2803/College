#include<stdio.h>

int main(void)
{
	char a;
	printf("���ڸ� �Է��Ͻÿ� : ");

	while ((a = getchar()) != '.')
	{
		//fflush(stdin);
		//sd input,, S \n D output,,
		if (islower(a))
		{
			a = toupper(a);
			putchar(a);
			printf("\n");
		}
		else if (isupper(a))
		{
			a = tolower(a);
			putchar(a);
			printf("\n");
		}
	}
}
//20191129