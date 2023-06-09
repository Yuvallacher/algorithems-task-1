#ifndef _DIRECTED_GRAPH_H
#define _DIRECTED_GRAPH_H

#include "Graph.h"

class DirectedGraph : public Graph
{
	vector<int> inDegree;
	vector<int> outDegree;
public:
	DirectedGraph(int n, int m);
	virtual void AddEdge(Vertex u, Vertex v) override;
	bool checkDegrees() const;
	DirectedGraph getTransposeGraph(DirectedGraph& other) const;
	virtual bool checkConnectivity() override;
	virtual bool isAulerian() override;
	virtual list<Vertex> findCircuit(Vertex& v) override;
};


#endif //_DIRECTED_GRAPH_H