#include "Graph.h"

Graph::Graph(int n, int m) 
{
	numVertices = n;
	numEdges = m;
	edges.reserve(numVertices);
	list<Vertex> empty;
	for (int i = 0; i < numVertices; i++)
		edges.push_back(empty);
}


list<Vertex> Graph::neighborList(int u)  const
{
	return edges[u - 1];
}


bool Graph::areNeighbors(Vertex u, Vertex v)	const
{
	list<Vertex>::const_iterator itr = edges[u.num - 1].begin();
	list<Vertex>::const_iterator itrEnd = edges[u.num - 1].end();
	
	for (; itr != itrEnd; ++itr)
		if (*(itr) == v)
			return true;
	return false;
}


void Graph::visit(Vertex u, string* colors, bool* edgesColors)
{
	colors[u.num - 1] = "grey";
	list<Vertex> neighbors = this->neighborList(u.num);
	list<Vertex>::iterator itr = neighbors.begin();
	list<Vertex>::iterator itrEnd = neighbors.end();

	for (; itr != itrEnd; ++itr)
	{
		//markEdge(u, *itr, colors, edgesColors);
		visit(*itr, colors, edgesColors);
	}
	colors[u.num - 1] = "black";
}

//void Graph::markEdge(int u, int v, string* colors, bool* edgesColors)
//{
//	if (colors[v-1] == "white")
//
//}