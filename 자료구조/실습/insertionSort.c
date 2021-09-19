#include<stdio.h>
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

void insertionSort(int array[], int size) {
	for (int i = 1;i < size;i++) {
		int value = array[i];
		int j;
		for (j = i - 1;j >= 0;j--) {
			if (array[j] > value) {
				array[j + 1] = array[j];
			}
			else {
				break;
			}
		}
		array[j + 1] = value;
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

	insertionSort(a, LENGTH(a));
	print(a, LENGTH(a));
}
//20200706-5