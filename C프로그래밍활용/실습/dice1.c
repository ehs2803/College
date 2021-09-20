#include<stdio.h>
#include<stdlib.h>

#define size 6

int main(void)
{
	int freq1 = 0;
	int freq2 = 0;
	int freq3 = 0;
	int freq4 = 0;
	int freq5 = 0;
	int freq6 = 0;
	int i;

	for (i = 0; i < 10000; i++)
	{
		if (rand() % 6==0)
		{
			++freq1;
		}
		else if (rand() % 6 == 1)
		{
			++freq2;
		}
		else if (rand() % 6 == 2)
		{
			++freq3;
		}
		else if (rand() % 6 == 3)
		{
			++freq4;
		}
		else if (rand() % 6 == 4)
		{
			++freq5;
		}
		else if (rand() % 6 == 5)
		{
			++freq6;
		}
		
	}

	printf("======================\n");
	printf("¸é ºóµµ\n");
	printf("======================\n");

	
    printf("%3d %3d \n", 1, freq1);
	printf("%3d %3d \n", 2, freq2);
	printf("%3d %3d \n", 3, freq3);
	printf("%3d %3d \n", 4, freq4);
	printf("%3d %3d \n", 5, freq5);
	printf("%3d %3d \n", 6, freq6);
	
}