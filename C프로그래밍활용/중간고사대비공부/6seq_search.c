#include<stdio.h>

#define SIZE 10

int main(void)
{
	int i, key;
	int list[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };

	printf("Ž???? ???? ?Է??Ͻÿ?:");
	scanf_s("%d", &key);

	for (i = 0; i < SIZE; i++)
	{
		if (list[i] == key)
		{
			printf("Ž?? ???? ?ε???=%d\n", i);
		}
	}
	printf("Ž?? ????");
}
//20191011