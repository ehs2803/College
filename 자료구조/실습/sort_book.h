#ifndef __SORT_BOOK_H__
#define __SORT_BOOK_H__
#define BUCKET_NUM 10

void printarr(int arr[], int n);

void BubbleSort(int arr[], int n);

void SelSort(int arr[], int n);

void InserSort(int arr[], int n);

void HeapSort(int arr[], int n);

void mergesort(int arr[], int left, int right);
void MergeTwoArea(int arr[], int left, int mid, int right);

void QuickSort(int arr[], int left, int right);
int Partitionarr(int arr[], int left, int right);
void swaparr(int arr[], int idx1, int idx2);

void RadixSort(int arr[], int num, int maxLen);

#endif
//20200713-2
//20200715-3