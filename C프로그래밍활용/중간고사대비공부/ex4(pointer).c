#include<stdio.h>

int main(void)
{
	int an[5] = { 1,2,3,4,5 };
	int* ptr = &an[4];
	int sum = 0;
	int i;


	for (i = 0; i < 5; i++)
	{

		printf("ptr is %d\n", *ptr);

		sum = sum + *(ptr--);
	}




	printf("sum = %d", sum);

}
//20191025