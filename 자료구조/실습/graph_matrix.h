#ifndef __GRAPH_MATRIX_H__
#define __GRAPH_MATRIX_H__

typedef struct {
	int V;
	int E;
	int** M;
}graph_matrix;
typedef graph_matrix* graphPtr;

int** InintMatrix(int Row, int Ncol, int value);

graphPtr InintGraph_matrix(int V);

void InsertEdge(graphPtr g, int V1, int V2);

void FreeMatrix(int**m);

void getAdjacency_matrix(graphPtr g, int V);

#endif
//20200709-5