#include<stdio.h>
int scalar_mult(int a[][3], int scalar);

int main(void)
{
	int a[3][3] = {
	{1,2,3},
	{4,5,6},
	{7,8,9}
	};

	scalar_mult(a[3][3], 2);

}

int scalar_mult(int a[][3], int scalar)
{
	int i,j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			a[i][j] = 2 * a[i][j];
		}
	}
	
}