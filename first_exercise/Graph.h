#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <list>

using namespace std;

class Graph
{
protected:
	int numVertices;
	int numEdges;

public:
	vector<list<int>> edges;
	Graph(int n, int m); 
	list<int> neighborList(int u)	const;
	bool areNeighbors(int u, int v)	const;
	virtual void AddEdge(int u, int v) = 0;
};


#endif