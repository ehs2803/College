#include<stdio.h>

int main(void)
{
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = arr;
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("�ʱ�迭��[%d] = %d\n", i,*ptr++);

		
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
		printf("�����Ĺ迭��[%d] = %d\n",i, *ptr++);

	}
}
//20191025