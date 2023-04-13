#include "NonDirectedGraph.h"

NonDirectedGraph::NonDirectedGraph(int n, int m) : Graph(n, m)
{}

void NonDirectedGraph::AddEdge(Vertex u, Vertex v)
{
	if (u.num > numVertices || u.num < 0 || v.num > numVertices || v.num < 0)
		throw "invalid input";
	edges[u.num - 1].first.push_back(v);
	edges[v.num - 1].first.push_back(u);
	auto it_v = prev(edges[u.num - 1].first.end());
	Vertex& v_ref = *it_v;
	auto it_u = prev(edges[v.num - 1].first.end());
	Vertex& u_ref = *it_u;

	v_ref.it = it_u;
	u_ref.it = it_v;	
}


bool NonDirectedGraph::checkEvenDegrees() const
{
	for (auto& item : this->edges)
	{
		if ((item.first.size() - 1) % 2 == 1)
			return false;
	}
	return true;
}


bool NonDirectedGraph::checkConnectivity()
{
	string* colors = new string[numVertices];
	for (int i = 0; i < numVertices; i++)
		colors[i] = "white";
	visit(edges[0].first.front(), colors);
	for (int i = 0; i < numVertices; i++)
		if (colors[i] != "black")
			return false;
	return true;
}


bool NonDirectedGraph::isAulerian()
{
	return (this->checkEvenDegrees() && this->checkConnectivity());
}


list<Vertex> NonDirectedGraph::findCircuit(Vertex& v)
{
	Vertex* ver = &v;
	list<Vertex> circuitList;
	circuitList.push_back(v);
	do {
		this->getNextUnmarkedEdge((*ver).num);
		list<Vertex>::iterator itr = edges[(*ver).num - 1].second;
		Vertex& u = *(itr);
		
		if (itr == prev(edges[(*ver).num - 1].first.end())) // last neighbor of v 
		{
			if (u.visited == true) // v has no unused edge
				break;
		}
		
		u.visited = true; // mark (v,u)
		Vertex& v_temp = *(u.it); // v the neighbor of u
		v_temp.visited = true; // mark (u,v)
		circuitList.push_back(u);
		ver = &u;
	} while (next(edges[(*ver).num - 1].second) != edges[(*ver).num - 1].first.end());
	return circuitList;
}