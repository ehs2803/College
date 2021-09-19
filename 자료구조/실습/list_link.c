#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "list_link.h"

void Inint_link(listType_link* Lptr) {
	Lptr->count = 0;
	Lptr->Head = NULL;
}

int Length_link(listType_link* Lptr) {
	return Lptr->count;
}

bool IsEmpty_link(listType_link* Lptr) {
	if (Lptr->count == 0)return true;
	else return false;
}

void Insert_link(listType_link* Lptr, int position, int item) {
	if ((position < 1) || (position > Lptr->count + 1)) {
		printf("잘못된 위치값입니다.\n");
	}
	else {
		Nptr_list p = malloc(sizeof(node_list));
		p->Data = item;
		p->Next = NULL;
		if (position == 1) {
			p->Next = Lptr->Head;
			Lptr->Head = p;
		}
		else {
			Nptr_list Temp = Lptr->Head;
			for (int i = 1;i < position - 1;i++) {
				Temp = Temp->Next;
			}
			p->Next = Temp->Next;
			Temp->Next = p;
		}
		Lptr->count++;
	}
}



void Delete_link(listType_link* Lptr, int position) {
	if (IsEmpty_link(Lptr)) {
		printf("리스트가 비었습니다.\n");
	}
	else if ((position < 1) || (position > Lptr->count)) {
		printf("삭제할 수 없는 위치입니다.\n");
	}
	else {
		if (position == 1) {
			Nptr_list p = Lptr->Head;
			Lptr->Head = p->Next;
			free (p);
		}
		else {
			Nptr_list Temp = Lptr->Head;
			for (int i = 1;i < position - 1;i++) {
				Temp = Temp->Next;
			}
			Nptr_list p = Temp->Next;
			Temp->Next = p->Next;
			free(p);
		}
		Lptr->count--;
	}
}

void Update_link(listType_link* Lptr, int position, int item) {
	if (IsEmpty_link(Lptr)) {
		printf("리스트가 비었습니다.\n");
	}
	else if ((position < 1) || (position > Lptr->count)) {
		printf("잘못된 위치값입니다.\n");
	}
	else {
		Nptr_list Temp = Lptr->Head;
		for (int i = 0;i < position-1;i++) {
			Temp = Temp->Next;
		}
		Temp->Data=item;
	}
}

void Retrieve_link(listType_link* Lptr, int position, int* item) {
	if (IsEmpty_link(Lptr)) {
		printf("리스트가 비었습니다.\n");
	}
	else if ((position < 1) || (position > Lptr->count)) {
		printf("잘못된 위치값입니다.\n");
	}
	else {
		Nptr_list Temp = Lptr->Head;
		for (int i = 0;i < position - 1;i++) {
			Temp = Temp->Next;
		}
		item = Temp->Data;
	}
}
//20200706-3