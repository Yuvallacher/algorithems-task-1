#ifndef _NON_DIRECTED_GRAPH_H
#define _NON_DIRECTED_GRAPH_H

#include "Graph.h"

class NonDirectedGraph : public Graph
{
public:
	NonDirectedGraph(int n, int m);
	virtual void AddEdge(int u, int v) override;
};


#endif _NON_DIRECTED_GRAPH_H