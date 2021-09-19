#include<stdio.h>
#include "graph_link.h"

graph_link* InintGraph_link(int V) {
	graph_link* G = malloc(sizeof(graph_link));
	G->V = V;
	G->E = 0;
	G->L = malloc(V * sizeof(node_graph*));
	for (int i = 0;i < G->V;i++) {
		G->L[i] = NULL;
	}
	return G;
}

void InsertEdge_link(graph_link* g, int V1, int V2) {
	node_graph* temp = malloc(sizeof(node_graph));
	temp->data = V2;
	temp->Next = g->L[V1];
	g->L[V1] = temp;
}

void getAdjacency(graph_link* g, int V) {
	if (g->L[V] == NULL) {
		printf("인접하는 정점이 없습니다.\n");
	}
	else {
		node_graph* temp = g->L[V];
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->Next;
		}
	}
}
//20200709-5