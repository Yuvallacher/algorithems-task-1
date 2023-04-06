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

void DirectedGraph::AddEdge(int u, int v)
{
	edges[u - 1].push_back(v);
	inDegree[v - 1]++;
	outDegree[u - 1]++;
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


DirectedGraph DirectedGraph::getTransposeGraph(DirectedGraph& other) const
{
	DirectedGraph transpose(other.numVertices, other.numEdges);
	for ( int i = 0; i < other.edges.size(); i++)
	{
		list<int> adjList = other.neighborList(i);
		list<int>::const_iterator itr = adjList.begin();
		list<int>::const_iterator itrEnd = adjList.end();
		for (; itr != itrEnd; ++itr)
		{
			transpose.AddEdge(*itr, i);
		}
	}
	return transpose;
}