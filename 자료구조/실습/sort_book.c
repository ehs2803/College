#include<stdio.h>
#include "sort_book.h"
#include "heap.h"
#include "queue_link.h"

void printarr(int arr[], int n) {
	printf("[ ");
	for (int i = 0;i < n;i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

void BubbleSort(int arr[], int n) {
	int i, j;
	int temp;

	for (i = 0; i < n - 1;i++) {
		for (j = 0;j < (n - i) - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void SelSort(int arr[], int n) {
	int i, j;
	int maxIdx;
	int temp;

	for (i = 0;i < n - 1;i++) {
		maxIdx = i;

		for (j = i + 1;j < n;j++) {
			if (arr[j] < arr[maxIdx]) {
				maxIdx = j;
			}

			temp = arr[i];
			arr[i] = arr[maxIdx];
			arr[maxIdx] = temp;
		}
	}
}

void InserSort(int arr[], int n) {
	int i, j;
	int insData;

	for (i = 1;i < n;i++) {
		insData = arr[i];

		for (j = i - 1;j >= 0;j--) {
			if (arr[j] > insData) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		
		arr[j + 1] = insData;
	}
}

void HeapSort(int arr[], int n) {
	Heap H;
	Inint_heap(&H);
	for (int i = 0;i < n;i++) {
		Add_heap(&H, arr[i]);
	}
	printf("ÈüÁ¤·Ä : ");
	while (!IsEmpty_heap(&H)) {
		Remove_heap(&H);
	}
	printf("\n");
}

void mergesort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}
void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) {
		if (arr[fIdx] <= arr[rIdx]) {
			sortArr[sIdx] = arr[fIdx++];
		}
		else {
			sortArr[sIdx] = arr[rIdx++];
		}
		sIdx++;
	}

	if (fIdx > mid) {
		for (i = rIdx;i <= right;i++, sIdx++) {
			sortArr[sIdx] = arr[i];
		}
	}
	else {
		for (i = fIdx;i <= mid;i++, sIdx++) {
			sortArr[sIdx] = arr[i];
		}
	}

	for (i = left;i <= right;i++) {
		arr[i] = sortArr[i];
	}
	free(sortArr);
}

void QuickSort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = Partitionarr(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}
int Partitionarr(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot > arr[low]) {
			low++;
		}

		while (pivot < arr[high]) {
			high--;
		}
		if (low <= high) {
			swaparr(arr, low, high);
		}
	}

	swaparr(arr, left, high);
	return high;
}
void swaparr(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void RadixSort(int arr[], int num, int maxLen) {
	Queue_link bucket[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	for (bi = 0;bi < BUCKET_NUM;bi++) {
		Inint_queue_link(&bucket[bi]);
	}

	for (pos = 0;pos < maxLen;pos++) {
		for (di = 0;di < num;di++) {
			radix = (arr[di] / divfac) % 10;
			Add_link(&bucket[radix], arr[di]);
		}

		for (bi = 0, di = 0;bi < BUCKET_NUM;bi++) {
			while (!IsEmpty_queue_link(&bucket[bi])) {
				arr[di++] = Remove_link(&bucket[bi]);
			}
		}

		divfac *= 10;
	}
}
//20200713-2
//20200715-3