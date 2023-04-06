#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <list>
#include "Vertex.h"

using namespace std;

class Graph
{
protected:
	int numVertices;
	int numEdges;

public:
	vector<list<Vertex>> edges;
	Graph(int n, int m); 
	list<Vertex> neighborList(int u)		const;
	bool areNeighbors(Vertex u, Vertex v)	const;
	virtual void AddEdge(Vertex u, Vertex v) = 0;
	void visit(Vertex u, string* colors, bool* edgesColors);
	void markEdge(Vertex u, Vertex v, string* colors, bool* edgesColors);
};


#endif