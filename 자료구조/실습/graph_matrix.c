#include<stdio.h>
#include "graph_matrix.h"

int** InintMatrix(int Row, int Ncol, int value) {
	int** m;
	m = malloc(Row * sizeof(int*));
	for (int i = 0;i < Row;i++) {
		m[i] = malloc(Ncol * sizeof(int));
	}
	for (int i = 0;i < Row;i++) {
		for (int j = 0;j < Ncol;j++) {
			m[i][j] = value;
		}
	}
	return m;
}

graphPtr InintGraph_matrix(int V) {
	graphPtr G = malloc(sizeof(graph_matrix));
	G->V = V;
	G->E = 0;
	G->M = InintMatrix(V, V, 0);
	return G;
}

void InsertEdge(graphPtr g, int V1, int V2) {
	if (g->M[V1][V2] == 0) {
		g->E++;
		g->M[V1][V2] = 1;
	}
}

void FreeMatrix(graphPtr g) {
	for (int i = 0;i < g->V;i++) {
		free(g->M[i]);
	}
	free(g->M);
}

void getAdjacency_matrix(graphPtr g, int V) {
	int c=0;
	for (int i = 0;i < g->V;i++) {
		if (g->M[V][i] == 1) {
			if (V != i) {
				printf("%d ", i);
				c = 1;
			}
		}
	}
	if (c == 0) {
		printf("인접하는 정점이 없습니다.\n");
	}
}
//20200709-5