#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(int n, int m) : Graph(n, m)
{
	inDegree.reserve(n);
	outDegree.reserve(n);
	for (int i = 0; i < n; i++)
	{
		inDegree.push_back(0);
		outDegree.push_back(0);
	}
}

void DirectedGraph::AddEdge(Vertex u, Vertex v)
{
	edges[u.num - 1].push_back(v);
	inDegree[v.num - 1]++;
	outDegree[u.num - 1]++;
}

bool DirectedGraph::checkDegrees() const
{
	for ( int i = 0; i < edges.size(); i++)
	{
		if ( outDegree[i] != inDegree[i] )
		{
			return false;
		}
	}
	return true;
}


DirectedGraph& DirectedGraph::getTransposeGraph(DirectedGraph& other) const
{
	DirectedGraph transpose(other.numVertices, other.numEdges);

	for (int i = 0; i < other.edges.size(); i++)
	{
		list<Vertex> adjList = other.neighborList(i);
		list<Vertex>::const_iterator itrTranspose = adjList.begin();
		list<Vertex>::const_iterator itrEndTranspose = adjList.end();
		for (; itrTranspose != itrEndTranspose; ++itrTranspose)
		{
			transpose.AddEdge(*itrTranspose, i);
		}
	}
	return transpose;
}