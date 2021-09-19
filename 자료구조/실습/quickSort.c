#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int partition(int a[], int start, int end) {
	int value = a[end];
	int i = start - 1;
	for (int j = start;j <= end;j++) {
		if (a[j] < value) {
			swap(a, ++i, j);
		}
	}
	swap(a, i + 1, end);
	return i + 1;
}

void quickSort(int a[], int start, int end) {
	if (start >= end)return;
	int middle = partition(a, start, end);
	quickSort(a, start, middle - 1);
	quickSort(a, middle + 1, end);

}

void print(int array[], int size) {
	printf("[ ");
	for (int i = 0;i < size;i++) {
		printf("%d ", array[i]);
	}
	printf("]\n");
}

int main(void) {
	srand(time(NULL));
	int a[10];
	for (int i = 0;i < LENGTH(a);i++) {
		a[i] = rand() % 20;
	}
	print(a, LENGTH(a));

	quickSort(a, 0, LENGTH(a) - 1);
	print(a, LENGTH(a));
}
//20200706-8