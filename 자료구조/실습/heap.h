#ifndef __HEAP_H__
#define __HEAP_H__
#define MAX 50
#include<stdbool.h>

typedef struct node_h {
	int count;
	int HEAP[MAX];
}Heap;

void Inint_heap(Heap* hptr);

bool IsEmpty_heap(Heap* hptr);

void Add_heap(Heap* hptr, int item);

void Remove_heap(Heap* hptr);

void DownHeap(Heap* hptr, int current);

#endif
//20200709-3