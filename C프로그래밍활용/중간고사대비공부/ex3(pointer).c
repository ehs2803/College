#include<stdio.h>

int main(void)
{
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = arr;
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("초기배열값[%d] = %d\n", i,*ptr++);

		
	}

	ptr = arr;

	for (i = 0; i < 5; i++)
	{
		*ptr = *ptr + 4;
		ptr++;
	}

	ptr = arr;

	for (i = 0; i < 5; i++)
	{
		printf("연산후배열값[%d] = %d\n",i, *ptr++);

	}
}
//20191025