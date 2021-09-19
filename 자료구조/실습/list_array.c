#include<stdio.h>
#include<stdbool.h>
#include "list_array.h"

void Inint_array(listType_array* Lptr) {
	Lptr->count = 0;
}

int Length_array(listType_array* Lptr) {
	return Lptr->count;
}

bool IsEmpty_array(listType_array* Lptr) {
	if (Lptr->count == 0)return true;
	else return false;
}

void Insert_array(listType_array* Lptr, int position, int item) {
	if (Lptr->count == MAX) {
		printf("리스트가 꽉 찼습니다.\n");
	}
	else if ((position < 1) || (position > Lptr->count+1)) {
		printf("잘못된 위치값입니다.\n");
	}
	else {
		for (int i = (Lptr->count - 1);i >= (position - 1);i--) {
			Lptr->Data[i + 1] = Lptr->Data[i];
		}
		Lptr->Data[position - 1] = item;
		Lptr->count++;
	}
}


void Delete_array(listType_array* Lptr, int position) {
	if (IsEmpty_array(Lptr)) {
		printf("리스트가 비었습니다.\n");
	}
	else if ((position<1)||(position>Lptr->count)) {
		printf("삭제할 수 없는 위치입니다.\n");
	}
	else {
		for (int i = position - 1;i < (Lptr->count - 1);i++) {
			Lptr->Data[i] = Lptr->Data[i + 1];
		}
		Lptr->count--;
	}
}

void Update_array(listType_array* Lptr, int position, int item) {
	if (IsEmpty_array(Lptr)) {
		printf("리스트가 비었습니다.\n");
	}
	else if ((position < 1) || (position > Lptr->count)) {
		printf("잘못된 위치값입니다.\n");
	}
	else {
		Lptr->Data[position - 1] = item;
	}
}

void Retrieve_array(listType_array* Lptr, int position, int* item) {
	if (IsEmpty_array(Lptr)) {
		printf("리스트가 비었습니다.\n");
	}
	else if ((position < 1) || (position > Lptr->count)) {
		printf("잘못된 위치값입니다.\n");
	}
	else {
		item = Lptr->Data[position - 1];
	}
}
//20200706-3