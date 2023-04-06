#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <list>
#include <string>

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
	void visit(int u, string* colors, bool* edgesColors);
	void markEdge(int u, int v, string* colors, bool* edgesColors);
};


#endif