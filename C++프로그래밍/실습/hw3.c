#include<iostream>

typedef struct nodeRecord {
	int data;
	struct nodeRecord* LChild;
	struct nodeRecord* RChild;
}node;
typedef node* Nptr;

void InOrder(Nptr T) {
	if (T != NULL) {
		InOrder(T->LChild);
		Visit(T);
		InOrder(T->RChild);
	}
}

Nptr Insert(Nptr T, int key) {
	if (T == NULL) {
		T = (node*)malloc(sizeof(node));
		T->data = key;
		T->LChild = NULL; T->RChild = NULL;
	}
	else if (T->data > key) {
		T->LChild = Insert(T->LChild, key);
	}
	else {
		T->RChild = Insert(T->RChild, key);
	}
	return T;
}

void Visit(Nptr T) {
	printf("%d ", T->data);
}

int main(void) {
	int input;
	int i;
	Nptr T;
	printf("정수 20개를 입력하세요 : ");
	for (i = 0; i < 20; i++) {
		scanf("%d", &input);
		Insert(T, input);
	}

	InOrder(T);
}