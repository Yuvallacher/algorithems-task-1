#include "NonDirectedGraph.h"

NonDirectedGraph::NonDirectedGraph(int n, int m) : Graph(n, m)
{}

void NonDirectedGraph::AddEdge(Vertex u, Vertex v)
{
	edges[u.num - 1].push_back(v);
	edges[v.num - 1].push_back(u);
}

bool NonDirectedGraph::checkEvenDegrees() const
{
	int numofOddDegrees = 0;
	vector<list<Vertex>>::const_iterator itr = edges.begin();
	vector<list<Vertex>>::const_iterator itrEnd = edges.end();

	for (; itr != itrEnd && numofOddDegrees <= 2; ++itr)
	{
		if (itr->size() % 2 == 1)
			numofOddDegrees++;
	}
	return ((numofOddDegrees == 0) || (numofOddDegrees == 2));
}