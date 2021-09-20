#include<stdio.h>

#define SIZE 20

int input_number(int a[SIZE]);

int main(void)
{
    int i, j, temp, least;
	int input[SIZE] = { 0 };
	input_number(input);

	for (int i = 0; i < 20; i++)
	{
		printf("%d ", input[i]);
	}
	printf("\n");
	for (i = 0; i < SIZE - 1; i++)
	{

		least = i;

		for (j = i + 1; j < SIZE; j++)
			if (input[j] < input[least])
				least = j;
		temp = input[i];
		input[i] = input[least];
		input[least] = temp;
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", input[i]);
	}
	printf("\n");

	printf("%d\n", input[19]+input[18]);
	printf("%d %d",input[19] ,input[18] );
}

int input_number(int a[SIZE])
{
	int i;
	int j = 0;

	printf("input number : ");

	for (i=0;i<SIZE;i++)
	{
		scanf_s("%d", &j);
		a[i] = j;
	}
}

int max_number(int a[SIZE])
{
	int i, max;
	max = 0;

	for (i = 0; i < SIZE; i++)
	{
		
	}
}
//20191009