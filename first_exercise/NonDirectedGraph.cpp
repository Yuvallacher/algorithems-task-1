#include "NonDirectedGraph.h"

NonDirectedGraph::NonDirectedGraph(int n, int m) : Graph(n, m)
{}

void NonDirectedGraph::AddEdge(int u, int v) 
{
	edges[u - 1].push_back(v);
	edges[v - 1].push_back(u);
}
