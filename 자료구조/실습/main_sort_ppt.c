#include "sort.h"

int main(void) {
	int a[] = { 1,5,0,50,-1,30,25,45,22,33 };
	Selection(a, 10);
	print(a, 10);

	int b[] = { 1,5,0,50,-1,30,25,45,22,33 };
	Bubble(b, 10);
	print(b, 10);

	int c[] = { 1,5,0,50,-1,30,25,45,22,33 };
	Insertion(c, 10);
	print(c, 10);

	int d[] = { 1,5,0,50,-1,30,25,45,22,33 };
	MergeSort(d, 0, 9);
	print(d, 10);

	int e[] = { 1,5,0,50,-1,30,25,45,22,33 };
	quickSort(e, 0, 9);
	print(e, 10);
}
//20200710-3