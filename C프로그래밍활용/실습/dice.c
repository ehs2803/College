#include<stdio.h>
#include<stdlib.h>

#define size 6

int main(void)
{
	int freq[size] = { 0 };
	int i;

	for (i = 0; i < 10000; i++)
	{
		++freq[rand() % 6];
	}

	printf("======================\n");
	printf("�� ��\n");
	printf("======================\n");

	for (i = 0; i < size; i++)
	{
		printf("%3d %3d \n", i + 1, freq[i]);
	}
}