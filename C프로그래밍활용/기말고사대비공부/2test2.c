#include<stdio.h>

int main(void)
{
	char a[10];
	int i;

	scanf_s("%s", a,10);

	for (i = 0; a[i]!=NULL; i++)
	{
		if (a[i] == 'c')
		{
			printf("c");
		}
		if (a[i] == 'b')//=연산자 사용 못함. ==사용해야만함.
		{
			printf("b");
		}
	}
}
//20191120