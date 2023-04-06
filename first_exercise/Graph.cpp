#include "Graph.h"

Graph::Graph(int n, int m) 
{
	numVertices = n;
	numEdges = m;
	edges.reserve(numVertices);
	list<int> empty;
	for (int i = 0; i < numVertices; i++)
		edges.push_back(empty);
}


list<int> Graph::neighborList(int u)  const
{
	return edges[u];
}


bool Graph::areNeighbors(int u, int v)	const
{
	list<int>::const_iterator itr = edges[u].begin();
	list<int>::const_iterator itrEnd = edges[u].end();
	
	for (; itr != itrEnd; ++itr)
		if (*(itr) == v)
			return true;
	return false;
}


void Graph::visit(int u, string* colors, bool* edgesColors)
{
	colors[u - 1] = "grey";
	list<int> neighbors = this->neighborList(u);
	list<int>::iterator itr = neighbors.begin();
	list<int>::iterator itrEnd = neighbors.end();

	for (; itr != itrEnd; ++itr)
	{
		//markEdge(u, *itr, colors, edgesColors);
		visit(*itr, colors, edgesColors);
	}
	colors[u - 1] = "black";
}

//void Graph::markEdge(int u, int v, string* colors, bool* edgesColors)
//{
//	if (colors[v-1] == "white")
//
//}