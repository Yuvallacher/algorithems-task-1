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
