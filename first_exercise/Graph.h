#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <list>
#include "Vertex.h"
#include <iostream>
using namespace std;

class Graph
{
protected:
	int numVertices;
	int numEdges;
	vector<pair<list<Vertex>, list<Vertex>::iterator>> edges;
	
public:
	Graph(int n, int m); 
	list<Vertex> neighborList(const Vertex& u)			const;
	bool areNeighbors(const Vertex& u, const Vertex& v)	const;
	virtual void AddEdge(Vertex u, Vertex v) = 0;
	virtual bool checkConnectivity() = 0;
	void visit(const Vertex& u, string* colors) ;
	void getNextUnmarkedEdge(int i);
	virtual bool isAulerian() = 0;
	virtual list<Vertex> findCircuit(Vertex& v) = 0;
	list<Vertex> euler();
	void getNextVertexWithUnusedEdges(list<Vertex>::iterator& itr, const list<Vertex>& list);
	void printEulerCircuit(const list<Vertex>& euler) const;
};


#endif