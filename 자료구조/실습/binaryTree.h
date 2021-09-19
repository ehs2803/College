#ifndef __BINARYTREE_H_
#define __BINARYTREE_H__

typedef struct Node_tree {
	int data;
	struct Node_tree* Lchild;
	struct Node_tree* Rchild;
}node_tree;

void preorder(node_tree* Tptr);

void Inorder(node_tree* Tptr);

void postorder(node_tree* Tptr);

node_tree* Insert_tree(node_tree* Tptr, int item);

#endif
//20200709-3