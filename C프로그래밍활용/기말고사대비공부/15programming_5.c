#include<stdio.h>

int main(void)
{
	char a;
	printf("���ڸ� �Է��Ͻÿ� : ");

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