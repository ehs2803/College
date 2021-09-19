#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char vertexName[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
typedef struct
{
	int V;
	int E;
	int** M;
}graphType;
typedef graphType* graphPtr;

int** InintMatrix(int Row, int Ncol, int Value) {
	int** m;
	int i, j;
	m = malloc(Row * sizeof(int*));
	for (i = 0; i < Row; i++) {
		m[i] = malloc(Ncol * sizeof(int));
	}
	for (i = 0; i < Row; i++) {
		for (j = 0; j < Ncol; j++) {
			m[i][j] = Value;
		}
	}
	return m;
}

graphPtr InintGraph(int V) {
	graphPtr G = malloc(sizeof(graphType));
	G->V = V;
	G->E = 0;
	G->M = InintMatrix(V, V, 0);
	return G;
}

void InsertEdge(graphPtr graph, int V1, int V2, int weight) {
	if (graph->M[V1][V2] == 0 && graph->M[V2][V1] == 0)
	{
		graph->E++;
		graph->M[V1][V2] = weight;
		graph->M[V2][V1] = weight;
	}
	else
	{
		graph->M[V1][V2] = weight;
		graph->M[V2][V1] = weight;
	}
}

void FreeMatrix(graphPtr graph) {
	int i;
	for (i = 0; i < graph->V; i++) {
		free(graph->M[i]);
	}
	free(graph->M);
}

void PrintGraph(graphPtr graph)
{
	int i, j;
	printf("\n");
	printf(" ");
	for (i = 0; i < graph->V; i++)
	{
		printf("%2c ", vertexName[i]);
	}
	printf("\n");
	for (i = 0; i < graph->V; i++) {
		printf("%c ", vertexName[i]);
		for (j = 0; j < graph->V; j++) {
			printf("%02d ", graph->M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int searchMinVertex(int size, int* Distance, int* Selected)
{
	int i, minVertex;
	for (i = 0; i < size; i++)
	{
		if (Selected[i] == 0 && Distance[i] != -1)
		{
			minVertex = i;
			break;
		}
	}
	for (i = 0; i < size; i++)
	{
		if (Selected[i] == 0 && Distance[i] != -1 && (Distance[i] < Distance[minVertex])) minVertex = i;
	}
	return minVertex;
}

void updateDistance(graphPtr graph, int* Distance, int* Selected, int* LinkVertex, int minVertex)
{
	int i;
	for (i = 0; i < graph->V; i++)
	{
		if (Selected[i] == 0)
		{
			if (Distance[i] == -1)
			{
				if (graph->M[i][minVertex] > 0)
				{
					Distance[i] = graph->M[i][minVertex];
					LinkVertex[i] = minVertex;
				}
			}
			else
			{
				if (graph->M[i][minVertex] != 0 && graph->M[i][minVertex] < Distance[i])
				{
					Distance[i] = graph->M[i][minVertex];
					LinkVertex[i] = minVertex;
				}
			}
		}
	}
}

graphPtr Prim(graphPtr graph)
{
	int i;
	int minVertex;
	int intStartVertex;
	char chStartVertex;

	graphPtr MST = InintGraph(graph->V);

	int* Distance = malloc(sizeof(int) * graph->V);
	int* LinkVertex = malloc(sizeof(int) * graph->V);
	int* Selected = malloc(sizeof(int) * graph->V);

	for (i = 0; i < graph->V; i++) Distance[i] = -1;
	for (i = 0; i < graph->V; i++) Selected[i] = 0;

	printf("시작 정점을 입력하세요 : ");  scanf_s("%c", &chStartVertex);
	intStartVertex = chStartVertex - 65;

	Distance[intStartVertex] = 0;
	Selected[intStartVertex] = 1;

	for (i = 0; i < graph->V; i++)
	{
		if (i != intStartVertex && graph->M[intStartVertex][i] > 0)
		{
			Distance[i] = graph->M[intStartVertex][i];
			LinkVertex[i] = intStartVertex;
		}
	}

	while (MST->E < graph->V - 1)
	{
		minVertex = searchMinVertex(graph->V, Distance, Selected);
		Selected[minVertex] = 1;
		InsertEdge(MST, minVertex, LinkVertex[minVertex], Distance[minVertex]);

		updateDistance(graph, Distance, Selected, LinkVertex, minVertex);	
	}

	free(Distance);
	free(LinkVertex);
	free(Selected);
	return MST;
}

void SetEdge(graphPtr graph)
{
	srand(time(NULL));
	int* countEdge = malloc(sizeof(int) * graph->V);
	int i, j, edge, m, value;
	for (i = 0; i < graph->V; i++) countEdge[i] = 0;
	for (i = 0; i < graph->V; i++)
	{
		m = 0;
		while (countEdge[i] < 4)
		{
			edge = rand() % graph->V;
			while(edge==i) edge = rand() % graph->V;
			value = rand() % 50;
			if (countEdge[edge] == 4 && graph->M[edge][i]!=0)
			{
				InsertEdge(graph, edge, i, value); 
				m++;
			}
			else if(countEdge[edge]<4 && graph->M[edge][i]==0)
			{
				InsertEdge(graph, edge, i, value); 
				m++; 
				countEdge[i] += 1; 
				countEdge[edge] += 1;
			}
			else if (countEdge[edge] < 4 && graph->M[edge][i] != 0) {
				m++; 
				InsertEdge(graph, edge, i, value);
			}
			if (m == 4)break;
		}
	}
}

int main(void)
{
	graphType* Graph = InintGraph(26);
	SetEdge(Graph);
	PrintGraph(Graph);

	graphType* MST= Prim(Graph);
	PrintGraph(MST);
	printf("간선 수 : %d\n", MST->E);

	FreeMatrix(Graph);
	FreeMatrix(MST);
}

/*
InsertEdge(Graph, 0, 1, 3);
	InsertEdge(Graph, 1, 2, 1);
	InsertEdge(Graph, 2, 5, 1);
	InsertEdge(Graph, 4, 5, 9);
	InsertEdge(Graph, 4, 0, 4);
	InsertEdge(Graph, 1, 5, 2);
	InsertEdge(Graph, 0, 3, 2);
	InsertEdge(Graph, 3, 4, 5);
	InsertEdge(Graph, 1, 3, 4);
	InsertEdge(Graph, 3, 5, 7);
*/