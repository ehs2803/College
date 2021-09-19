#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char VertexName[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
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

void InsertEdge(graphPtr graph, int V1, int V2, int Weight) {
	if (graph->M[V1][V2] == 0 && graph->M[V2][V1]==0) 
	{
		graph->E++;
		graph->M[V1][V2] = Weight;
		graph->M[V2][V1] = Weight;
	}
	else 
	{		
		graph->M[V1][V2] = Weight;
		graph->M[V2][V1] = Weight;
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
		printf("%2c ", VertexName[i]);
	}
	printf("\n");
	for (i = 0; i < graph->V; i++) {
		printf("%c ", VertexName[i]);
		for (j = 0; j < graph->V; j++) {
			printf("%02d ", graph->M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
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
		if (i != intStartVertex && graph->M[intStartVertex][i]>0)
		{
			Distance[i] = graph->M[intStartVertex][i];
			LinkVertex[i] = intStartVertex;
		}
	}

	while (MST->E < graph->V-1)
	{
		for (i = 0; i < graph->V; i++)
		{
			if (Selected[i]==0 && Distance[i]!=-1)
			{
				minVertex = i;
				break;
			}
		}
		for (i = 0; i < graph->V; i++)
		{
			if(Selected[i]==0 && Distance[i]!=-1 && (Distance[i] < Distance[minVertex])) minVertex =i;
		}
		Selected[minVertex] = 1;
		InsertEdge(MST, minVertex, LinkVertex[minVertex], Distance[minVertex]);
		
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
					if (graph->M[i][minVertex]!=0 && graph->M[i][minVertex] < Distance[i])
					{
						Distance[i] = graph->M[i][minVertex];
						LinkVertex[i] = minVertex;
					}
				}
			}
		}
	}
	free(Distance);
	free(LinkVertex);
	free(Selected);
	return MST;
}

void SetEdge(graphPtr graph)
{
	srand(time(NULL));
	int i, j;
	for (i = 0; i < graph->V; i++)
	{
		for (j = 0; j < graph->V; j++)
		{
			if (i != j) graph->M[i][j] = rand() % 30;
		}
	}
}

int main(void)
{
	graphType *Graph = InintGraph(26);
	/*
	InsertEdge(Graph, 0, 6, 6);
	InsertEdge(Graph, 5, 7, 2);
	InsertEdge(Graph, 0, 5, 2);
	InsertEdge(Graph, 6, 7, 5);
	InsertEdge(Graph, 1, 2, 1);
	InsertEdge(Graph, 3, 4, 2);
	InsertEdge(Graph, 1, 3, 2);
	InsertEdge(Graph, 2, 4, 4);
	InsertEdge(Graph, 1, 4, 4);
	InsertEdge(Graph, 0, 1, 1);
	InsertEdge(Graph, 5, 3, 1);
	InsertEdge(Graph, 4, 6, 1);
	InsertEdge(Graph, 4, 5, 2);
	InsertEdge(Graph, 4, 7, 4);*/
	SetEdge(Graph);
	PrintGraph(Graph);


	graphType* MST = Prim(Graph);
	PrintGraph(MST);
	printf("%d\n", MST->E);

	FreeMatrix(Graph);
	FreeMatrix(MST);
}



/*
	InsertEdge(Graph, 0, 1, 3);//6
	InsertEdge(Graph, 1, 2, 1);
	InsertEdge(Graph, 2, 5, 1);
	InsertEdge(Graph, 4, 5, 9);
	InsertEdge(Graph, 4, 0, 4);
	InsertEdge(Graph, 1, 5, 2);
	InsertEdge(Graph, 0, 3, 2);
	InsertEdge(Graph, 3, 4, 5);
	InsertEdge(Graph, 1, 3, 4);
	InsertEdge(Graph, 3, 5, 7);

InsertEdge(Graph, 0, 1, 4);//9
	InsertEdge(Graph, 0, 7, 8);
	InsertEdge(Graph, 1, 7, 11);
	InsertEdge(Graph, 2, 1, 8);
	InsertEdge(Graph, 2, 3, 7);
	InsertEdge(Graph, 3, 4, 9);
	InsertEdge(Graph, 4, 5, 10);
	InsertEdge(Graph, 5, 6, 2);
	InsertEdge(Graph, 6, 7, 1);
	InsertEdge(Graph, 3, 5, 14);
	InsertEdge(Graph, 2, 5, 4);
	InsertEdge(Graph, 2, 8, 2);
	InsertEdge(Graph, 8, 7, 7);
	InsertEdge(Graph, 8, 6, 6);
*/