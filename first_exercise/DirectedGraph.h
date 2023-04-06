#ifndef _DIRECTED_GRAPH_H
#define _DIRECTED_GRAPH_H

#include "Graph.h"

class DirectedGraph : public Graph
{
public:
	DirectedGraph(int n, int m);
	virtual void AddEdge(int u, int v) override;
};


#endif _DIRECTED_GRAPH_H