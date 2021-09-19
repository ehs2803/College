#include<stdio.h>
#include<stdbool.h>
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void bubbleSort(int array[], int size) {
	for (int i = size - 1;i >= 1;i--) {
		for (int j = 0;j < i;j++) {
			if (array[j] > array[j + 1]) {
				swap(array, j, j + 1);
			}
		}
	}
}

void bubbleSort_improve(int array[], int size) {
	for (int i = size - 1; i >= 1; i--) {
		bool done = true;
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j + 1]) {
				swap(array, j, j + 1);
				done = false;
			}
		}
		if (done) break;
	}
}

void print(int array[], int size) {
	printf("[ ");
	for (int i = 0;i < size;i++) {
		printf("%d ", array[i]);
	}
	printf("]\n");
}

int main(void) {
	int a[] = { 17, 14, 11, 19, 13, 15, 18, 12, 16, 20 };
	int b[] = { 17, 14, 11, 19, 13, 15, 18, 12, 16, 20 };

	bubbleSort(a, LENGTH(a));
	print(a, LENGTH(a));

	bubbleSort_improve(b, LENGTH(b));
	print(b, LENGTH(b));
}
//20200706-5