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
		if (a[i] == 'b')//=������ ��� ����. ==����ؾ߸���.
		{
			printf("b");
		}
	}
}
//20191120