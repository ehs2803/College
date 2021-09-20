#include<stdio.h>

int main(void)
{
	int a[2][3] = {
		{10,20,30},
		{40,50,60}
	};

	printf("%d\n", *a[0]);
	printf("%d\n", *a[1]);
}
//20191025