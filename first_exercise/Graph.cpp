#include "Graph.h"
#include <exception>

Graph::Graph(int n, int m) 
{
	numVertices = n;
	numEdges = m;
	if (n <= 0)
	{
		throw "invalid input";
	}
	edges.reserve(numVertices);
	for (int i = 0; i < numVertices; i++)
	{
		list<Vertex> dummy;
		dummy.push_back(i + 1);
		edges.push_back(make_pair(dummy, dummy.begin()));
	}
	for (int i = 0; i < numVertices; i++) // set iterator to the beginning of each list
	{
		edges[i].second = edges[i].first.begin();
		Vertex& v = *(edges[i].second);
		v.visited = true;
	}
}


list<Vertex> Graph::neighborList(const Vertex& u)  const
{
	return edges[u.num - 1].first;
}


bool Graph::areNeighbors(const Vertex& u, const Vertex& v)	const
{
	list<Vertex>::const_iterator itr = edges[u.num - 1].first.begin();
	list<Vertex>::const_iterator itrEnd = edges[u.num - 1].first.end();
	
	for (; itr != itrEnd; ++itr)
		if (*(itr) == v)
			return true;
	return false;
}


//void Graph::visit(Vertex u, string* colors) 
//{
//	if (colors[u.num - 1] != "white")
//		return;
//
//	colors[u.num - 1] = "gray";		// colors is a new array with colors for the vertices, we need to create and initialize it before the call to visit
//	list<Vertex> neighbors = this->neighborList(u);
//	list<Vertex>::iterator itr = neighbors.begin();
//	list<Vertex>::iterator itrEnd = neighbors.end();
//
//	for (; itr != itrEnd; ++itr)
//	{
//		markEdge(*itr);
//		visit(*itr, colors);
//	}
//	colors[u.num - 1] = "black";
//}

void Graph::visit(const Vertex& u, string* colors) 
{
	colors[u.num - 1] = "gray";		// colors is a new array with colors for the vertices, we need to create and initialize it before the call to visit
	list<Vertex> neighbors = this->neighborList(u);
	list<Vertex>::iterator itr = neighbors.begin();
	list<Vertex>::iterator itrEnd = neighbors.end();
	++itr;
	for (; itr != itrEnd; ++itr)
	{
		Vertex& v = *itr;
		if (colors[v.num - 1] == "white")
		{
			markEdge(*itr);
			visit(*itr, colors);
		}
	}
	colors[u.num - 1] = "black";
}


void Graph::markEdge(Vertex& v)
{
	if (v.visited) // we've been to this vertex before
		return;
	else
		v.visited = true;
}

void Graph::getNextUnmarkedEdge(int i)
{	
	bool visited;
	do {
		edges[i-1].second = next(edges[i-1].second); // move iterator to next neighbor
		Vertex& v = *(edges[i-1].second);
		visited = v.visited;
	} while (visited == true && edges[i-1].second != prev(edges[i-1].first.end()) );
}

list<Vertex> Graph::euler()
{
	list<Vertex> eulerCircuit = findCircuit(this->edges[0].first.front());
	list<Vertex>::iterator itr = eulerCircuit.begin();
	getNextVertexWithUnusedEdges(itr, eulerCircuit);
	while (itr != prev(eulerCircuit.end()))
	{
		Vertex& v = *(itr);
		list<Vertex> pasteList = findCircuit(v);
		auto itr_temp = next(itr);
		auto itr_temp2 = prev(itr);
		eulerCircuit.erase(itr);
		eulerCircuit.splice(itr_temp, pasteList);
		itr = itr_temp2;
		getNextVertexWithUnusedEdges(itr, eulerCircuit);
	}
	return eulerCircuit;
}

void Graph::getNextVertexWithUnusedEdges(list<Vertex>::iterator& itr, const list<Vertex>& list)
{
	Vertex* last_neighbor_of_v = nullptr;
	int vertexNum;
	do {
		itr = next(itr);
		Vertex& v = *(itr);
		vertexNum = v.getNum();
		last_neighbor_of_v = &(*(prev(edges[vertexNum - 1].first.end())));
		//} while ( next(edges[vertexNum - 1].second) == edges[vertexNum - 1].first.end() && itr != prev(list.end()) ); // v doesnt have unused edges
	} while ( last_neighbor_of_v->visited == true && itr != prev(list.end())); // v doesnt have unused edges
}

void Graph::printEulerCircuit(const list<Vertex>& euler) const
{
	cout << "(";
	for (auto& item : euler)
	{
		cout << item.num << ",";
	}
	cout << "\b \b" << ")" << endl;
}