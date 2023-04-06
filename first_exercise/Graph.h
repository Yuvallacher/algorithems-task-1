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
	list<Vertex> neighborList(Vertex& u)		const;
	bool areNeighbors(Vertex u, Vertex v)	const;
	virtual void AddEdge(Vertex u, Vertex v) = 0;
	virtual bool checkConnectivity() = 0;
	void visit(Vertex u, string* colors);
	void markEdge(Vertex& v);
};


#endif