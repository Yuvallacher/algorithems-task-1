#ifndef _NON_DIRECTED_GRAPH_H
#define _NON_DIRECTED_GRAPH_H

#include "Graph.h"

class NonDirectedGraph : public Graph
{
public:
	NonDirectedGraph(int n, int m);
	virtual void AddEdge(Vertex u, Vertex v) override;
	bool checkEvenDegrees() const;
	virtual bool checkConnectivity() override;
	virtual bool isAulerian() override;
	virtual list<Vertex> findCircuit(Vertex& v)  override;
};


#endif //_NON_DIRECTED_GRAPH_H