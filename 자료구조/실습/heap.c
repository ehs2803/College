#include<stdio.h>
#include "heap.h"

void Inint_heap(Heap* hptr) {
	hptr->count = 0;
}

bool IsEmpty_heap(Heap* hptr) {
	if (hptr->count == 0)return true;
	else return false;
}

void Add_heap(Heap* hptr, int item) {
	int current, parent, temp;

	if (hptr->count == MAX) {
		printf("Heap Full\n");
	}
	else {
		hptr->HEAP[hptr->count] = item;
		current = hptr->count;
		parent = (current - 1) / 2;
		while ((current != 0) && (hptr->HEAP[current] < hptr->HEAP[parent])) {
			temp = hptr->HEAP[parent];
			hptr->HEAP[parent] = hptr->HEAP[current];
			hptr->HEAP[current] = temp;
			current = parent;
			parent = (current - 1) / 2;
		}
		hptr->count++;
	}
}

void Remove_heap(Heap* hptr) {
	printf("%d ", hptr->HEAP[0]);
	hptr->HEAP[0] = hptr->HEAP[hptr->count - 1];
	hptr->count--;
	DownHeap(hptr, 0);
}

void DownHeap(Heap* hptr, int current) {
	int child, Rchild, temp;
	if ((2*current*1)>=hptr->count) {

	}
	else {
		child = 2 * current + 1;
		if (hptr->count >= (2 * current + 2)) {
			Rchild = child + 1;
			if (hptr->HEAP[Rchild] < hptr->HEAP[child]) {
				child = Rchild;
			}
		}
		if (hptr->HEAP[current] > hptr->HEAP[child]) {
			temp = hptr->HEAP[current];
			hptr->HEAP[current] = hptr->HEAP[child];
			hptr->HEAP[child] = temp;
			DownHeap(hptr, child);
		}
	}
}
//20200709-3