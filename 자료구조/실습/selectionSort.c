#include<stdio.h>
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int findMin(int array[], int size, int start) {
	int minvalue = array[start];
	int minindex = start;
	for (int i = start + 1;i < size;i++) {
		if (array[i] < minvalue) {
		   minvalue = array[i];
		   minindex = i;
		}
	}
	return minindex;
}

void selectionSort(int array[], int size) {
	for (int i = 0;i < size - 1;i++) {
		int minindex = findMin(array, size, i);
		swap(array, i, minindex);
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
	int a[]={17, 14, 11, 19, 13, 15, 18, 12, 16, 20 };

	selectionSort(a, LENGTH(a));
	print(a, LENGTH(a));
}
//20200706-5