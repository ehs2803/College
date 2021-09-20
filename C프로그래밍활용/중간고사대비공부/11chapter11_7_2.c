#include<stdio.h>

#define N_DATA 10

void array_add(int a[], int b[], int c[], int size);
void array_print(char name, int* a, int size);

int main(void)
{
	int A[N_DATA] = { 1,2,3,4,5,6,7 };
	int B[N_DATA] = { 3,2,4,5,1,2,3 };
	int C[N_DATA] = { 0 };

	array_print('A', A, N_DATA);
	array_print('B', B, N_DATA);
	array_add(A, B, C, N_DATA);
	array_print('C', C, N_DATA);
}

void array_add(int* a, int* b, int* c, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		c[i] = a[i] + b[i];
	}
}

void array_print(char name, int* a, int size)
{
	int i;
	printf("%c[] = ", name);
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//20191018