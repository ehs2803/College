#include<stdio.h>
#include<stdbool.h>
#include "sort_ppt.h"

void print(int A[], int N) {
	printf("[ ");
	for (int i = 0;i < N;i++) {
		printf("%d ", A[i]);
	}
	printf("]\n");
}

void Selection(int A[], int N) {
	for (int Last = N - 1;Last >= 1;Last--) {
		int Larest = 0;
		for (int Current = 1;Current <= Last;Current++) {
			if (A[Current] > A[Larest]) {
				Larest = Current;
			}
		}
		int Temp = A[Last];
		A[Last] = A[Larest];
		A[Larest] = Temp;
	}
}

void Bubble(int A[], int N) {
	bool Sorted = false;
	for (int Pass = 1;(Pass < N) && (!Sorted);Pass++) {
		Sorted = true;
		for (int Current = 0;Current < N - Pass;Current++) {
			if (A[Current] > A[Current + 1]) {
				int Temp = A[Current];
				A[Current] = A[Current + 1];
				A[Current + 1] = Temp;
				Sorted = false;
			}
		}
		if (Sorted) {
			break;
		}
	}
}


/*
void Insertion(int A[], int N) {
	for (int Pick = 1;Pick < N;Pick++) {
		int Current = Pick;
		for (;(Current > 0) && (A[Current - 1] > A[Pick]);Current--) {
			A[Current] = A[Current - 1];
		}
		A[Current] = A[Pick];
	}
}
*/
void Insertion(int A[], int N){
	int temp;
	int i;
	int j;
	for (i = 1; i < N; i++){
		temp = A[i];
		j = i - 1;

		while ((j >= 0) && (temp < A[j])){
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = temp;
	}
}

void MergeSort(int A[], int First, int Last) {
	if (First < Last) {
		int Middle = (First + Last) / 2;
		MergeSort(A, First, Middle);
		MergeSort(A, Middle + 1, Last);
		Merge(A, First, Middle, Last);
	}
}

void Merge(int A[], int F, int Mid, int L) {
	int Temp[10];
	int First1 = F;
	int Last1 = Mid;
	int First2 = Mid + 1;
	int Last2 = L;
	int Index = First1;
	for (;(First1 <= Last1) && (First2 <= Last2);Index++) {
		if (A[First1] < A[First2]) {
			Temp[Index] = A[First1];
			First1++;
		}
		else {
			Temp[Index] = A[First2];
			First2++;
		}
	}
	for (;First1 <=Last1;First1++, Index++) {
		Temp[Index] = A[First1];
	}
	for (;First2 <= Last2;First2++, Index++) {
		Temp[Index] = A[First2];
	}
	for (Index = F;Index <= L;Index++) {
		A[Index] = Temp[Index];
	}
}

void quickSort(int A[], int first, int last){
	int pivot;
	int i;
	int j;
	int temp;
	if (first < last){
		pivot = first;
		i = first;
		j = last;
		while (i < j){
			while (A[i] <= A[pivot] && i < last){
				i++;
			}
			while (A[j] > A[pivot]){
				j--;
			}
			if (i < j){
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		temp = A[pivot];
		A[pivot] = A[j];
		A[j] = temp;

		quickSort(A, first, j - 1);
		quickSort(A, j + 1, last);
	}
}
/*
void QuickSort(int A[], int First, int Last) {
	if (First < Last) {
		int pivotIndex = Partition(A, First, Last);
		QuickSort(A, First, pivotIndex - 1);
		QuickSort(A, pivotIndex + 1, Last);
	}
}

int Partition(int A[], int first, int last) {
	int low, high, prvotindex, p;
	p = A[last];
	low = first;
	high = last - 1;
	while (low < high) {
		while (p > A[low])low++;
		while (p < A[high])high--;
		if (low < high) {
			int temp = A[low];
			A[low] = A[high];
			A[high] = temp;
		}
	}
	int temp = A[low];
	A[low] = A[high];
	A[high] = temp;
	return low;
}
*/
//20200710-3