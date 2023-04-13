#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(int n, int m) : Graph(n, m)
{
	inDegree.reserve(n);
	outDegree.reserve(n);
	for (int i = 0; i < n; i++)
	{
		inDegree.push_back(0);
		outDegree.push_back(0);
	}
}

void DirectedGraph::AddEdge(Vertex u, Vertex v)
{
	edges[u.num - 1].first.push_back(v);
	inDegree[v.num - 1]++;
	outDegree[u.num - 1]++;
}

bool DirectedGraph::checkDegrees() const
{
	for ( int i = 0; i < edges.size(); i++)
	{
		if ( outDegree[i] != inDegree[i] )
		{
			return false;
		}
	}
	return true;
}


DirectedGraph DirectedGraph::getTransposeGraph(DirectedGraph& other) const
{
	DirectedGraph transpose(other.numVertices, other.numEdges);

	for (int i = 0; i < other.edges.size(); i++)
	{
		list<Vertex> adjList = other.neighborList(other.edges[i].first.front());
		list<Vertex>::const_iterator itrTranspose = adjList.begin();
		list<Vertex>::const_iterator itrEndTranspose = adjList.end();
		++itrTranspose;
		for (; itrTranspose != itrEndTranspose; ++itrTranspose)
		{
			transpose.AddEdge(*itrTranspose, i+1);
		}
	}
	return transpose;
}


bool DirectedGraph::checkConnectivity() 
{
	string* colors = new string[numVertices];
	for (int i = 0; i < numVertices; i++)
		colors[i] = "white";
	visit(edges[0].first.front(), colors);
	for (int i = 0; i < numVertices; i++)
		if (colors[i] != "black")
		{
			return false;
		}
	DirectedGraph transpose = getTransposeGraph(*this);

	for (int i = 0; i < numVertices; i++)
		colors[i] = "white";

	transpose.visit(edges[0].first.front(), colors);
	for (int i = 0; i < numVertices; i++)
		if (colors[i] != "black")
			return false;
	
	return true;
}


bool DirectedGraph::isAulerian() 
{
	return ( this->checkDegrees() && this->checkConnectivity() );
}

list<Vertex> DirectedGraph::findCircuit(Vertex& v) 
{
	Vertex& ver = v;
	list<Vertex> circuitList;
	circuitList.push_back(v);
	do {
		this->getNextUnmarkedEdge(ver.num);
		list<Vertex>::iterator itr = edges[ver.num - 1].second;
		Vertex& u = *(itr);
		u.visited = true; // mark (v,u)
		circuitList.push_back(u);
		ver = u;
	} while (next(edges[ver.num - 1].second) != edges[ver.num - 1].first.end());
	return circuitList;
}