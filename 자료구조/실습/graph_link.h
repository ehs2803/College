#ifndef __GRAPH_LINK_H__
#define __GRAPH_LINK_H__

typedef struct node_g {
	int data;
	struct node_g* Next;
}node_graph;

typedef struct {
	int V;
	int E;
	node_graph** L;
}graph_link;

graph_link* InintGraph_link(int V);

void InsertEdge_link(graph_link* g, int V1, int V2);

void getAdjacency(graph_link* g, int V);

#endif
//20200709-5