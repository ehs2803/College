#include<stdio.h>
#include<stdlib.h>

#define SIZE 6

int main(void)
{
	int freq[SIZE] = { 0 };
	int i;

	for (i = 0; i < 10000; i++)
	{
		++freq[rand() % 6];// 다른방식으로 표현?
	}

	printf("======================\n");
	printf("면 빈도\n");
	printf("======================\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("%d %3d \n", i + 1, freq[i]);
	}
}
//20191010
