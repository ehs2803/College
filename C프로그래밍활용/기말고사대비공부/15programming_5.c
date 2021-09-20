#include<stdio.h>

int main(void)
{
	char a;
	printf("문자를 입력하시오 : ");

	while ((a = getchar()) != '.')
	{
		//fflush(stdin);

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
//20191110