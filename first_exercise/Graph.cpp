#include "Graph.h"

Graph::Graph(int n, int m) 
{
	numVertices = n;
	numEdges = m;
	edges.reserve(numVertices);
	list<Vertex> dummy;
	for (int i = 0; i < numVertices; i++)
	{
		dummy.push_back(i + 1);
		edges.push_back(dummy);
		dummy.clear();
	}
}


list<Vertex> Graph::neighborList(Vertex& u)  const
{
	return edges[u.num - 1];
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


void Graph::visit(Vertex u, string* colors)
{
	if (colors[u.num - 1] != "white")
		return;

	colors[u.num - 1] = "grey";		// colors is a new array with colors for the vertices, we need to create and initialize it before the call to visit
	list<Vertex> neighbors = this->neighborList(u);
	list<Vertex>::iterator itr = neighbors.begin();
	list<Vertex>::iterator itrEnd = neighbors.end();

	for (; itr != itrEnd; ++itr)
	{
		markEdge(*itr);
		visit(*itr, colors);
	}
	colors[u.num - 1] = "black";
}


void Graph::markEdge(Vertex& v)
{
	if (v.visited) // we've been to this vertex before
		return;
	else
		v.visited = true;
}