#include<stdio.h>
#include "binaryTree.h"

void preorder(node_tree* Tptr) {
	if(Tptr != NULL) {
		printf("%d ", Tptr->data);
		preorder(Tptr->Lchild);
		preorder(Tptr->Rchild);
	}
}

void Inorder(node_tree* Tptr) {
	if (Tptr != NULL) {	
		Inorder(Tptr->Lchild);
		printf("%d ", Tptr->data);
		Inorder(Tptr->Rchild);
	}
}

void postorder(node_tree* Tptr) {
	if (Tptr != NULL) {
		postorder(Tptr->Lchild);
		postorder(Tptr->Rchild);
		printf("%d ", Tptr->data);
	}
}

node_tree* Insert_tree(node_tree* Tptr, int item) {
	if (Tptr == NULL) {
		Tptr = malloc(sizeof(node_tree));
		Tptr->data = item;
		Tptr->Lchild = NULL;
		Tptr->Rchild = NULL;
	}
	else if (Tptr->data > item) {
		Tptr->Lchild = Insert_tree(Tptr->Lchild, item);
	}
	else {
		Tptr->Rchild = Insert_tree(Tptr->Rchild, item);
	}
	return Tptr;
}
//20200709-3