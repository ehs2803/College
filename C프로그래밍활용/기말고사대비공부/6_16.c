#include<stdio.h>

int main(void)
{
	char in[100];
	char a[100];
	int i, j, k, m;
	int len;

	gets(in);
	len = strlen(in);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < len-1; j++)
		{
			a[len - 1]= in[0];
			a[j] = in[j + 1];
		}
		a[len] = '\0';
		for (k = 0; k < len; k++)
		{
			printf("%c", a[k]);
		}
		printf("\n");
		for (m = 0;m<len;m++)
		{
			in[i] = a[i];
		}
		
	}
}//20191121+수정필요
/*#include<stdio.h>

int main(void)
{
	char in[100];
	char a[100];
	int i,j,k;
	int len;

	gets(in);
	len = strlen(in);

	for (i = 0; i < 3; i++)
	{
		for (j = 0;j<len;j++)
		{
			a[j] = in[j + 1];
		}
		for (k = 0; k < len; k++)
		{
			printf("%c", a[k]);
		}
		printf("\n");
	}
}
//20191120*/