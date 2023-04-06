#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(int n, int m) : Graph(n, m)
{}

void DirectedGraph::AddEdge(int u, int v)
{
	edges[u - 1].push_back(v);
}
