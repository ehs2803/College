#include<stdio.h>
#define SIZE 9
int binary_search(int list[], int n, int key);

int main(void)
{
	int list[SIZE] = { 3,1,5,2,7,9,6,4,8 };

	int i, j, temp, least, key;

	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
	printf(">>");
	printf("\n");

	for (i = 0; i < SIZE - 1; i++)
	{

		least = i;

		for (j = i + 1; j < SIZE; j++)
			if (list[j] < list[least])
				least = j;
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}

	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");


	printf("탐색할 값을 입력하시오:");
	scanf_s("%d", &key);
	printf("탐색 결과= %d\n", binary_search(list, SIZE, key));

}

int binary_search(int list[], int n, int key)
{
	int low, high, middle;

	low = 0;
	high = n - 1;

	while (low <= high)
	{
		printf("[%d %d]\n", low, high);
		middle = (low + high) / 2;
		if (key == list[middle])
		{
			return middle;
		}
		else if (key > list[middle])
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}

}