#include<stdio.h>

int main(void)
{
	char a[20];
	int i;

	printf("input");
	gets_s(a, 20);//리눅스에서는 fgets(a,20,stdin);

	printf("%s\n", a);
	for (i = 0; i < 20; i++)
	{
		if (a[i] == ' ')
		{

		}
		else if (a[i] == 0)
		{
			return 0;
		}
		else
		{
			printf("%c", a[i]);
		}
	}
}
//20191212