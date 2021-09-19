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
		printf("����Ʈ�� �� á���ϴ�.\n");
	}
	else if ((position < 1) || (position > Lptr->count+1)) {
		printf("�߸��� ��ġ���Դϴ�.\n");
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
		printf("����Ʈ�� ������ϴ�.\n");
	}
	else if ((position<1)||(position>Lptr->count)) {
		printf("������ �� ���� ��ġ�Դϴ�.\n");
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
		printf("����Ʈ�� ������ϴ�.\n");
	}
	else if ((position < 1) || (position > Lptr->count)) {
		printf("�߸��� ��ġ���Դϴ�.\n");
	}
	else {
		Lptr->Data[position - 1] = item;
	}
}

void Retrieve_array(listType_array* Lptr, int position, int* item) {
	if (IsEmpty_array(Lptr)) {
		printf("����Ʈ�� ������ϴ�.\n");
	}
	else if ((position < 1) || (position > Lptr->count)) {
		printf("�߸��� ��ġ���Դϴ�.\n");
	}
	else {
		item = Lptr->Data[position - 1];
	}
}
//20200706-3