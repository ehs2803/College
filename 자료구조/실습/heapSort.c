#include<stdio.h>
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void heapify(int a[], int k, int end) {
    int left = 2 * k + 1, right = 2 * k + 2;
    int larger;
    if (right <= end) {
        larger = (a[left] > a[right]) ? left : right;
    }   
    else if (left <= end) { 
        larger = left; 
    }
    else { 
        return; 
    }
    if (a[larger] > a[k]) {
        swap(a, larger, k);
        heapify(a, larger, end);
    }
}
void buildHeap(int a[]) {
    int end = 10 -1;
    for (int i = end / 2; i >= 0; --i) {
        heapify(a, i, end);
    }

}
void heapSort(int a[]) {
    buildHeap(a);
    for(int end = 10 - 1; end >= 1; end--) {
        swap(a, 0, end);
        heapify(a, 0, end - 1);
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
    int a[] = { 3, 8, 2, 10, 4, 6, 7, 1, 9, 5 };
    heapSort(a);
    print(a, LENGTH(a));
}
//20200706-8