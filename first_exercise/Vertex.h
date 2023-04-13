#ifndef _VERTEX_H
#define _VERTEX_H


#include <list>
#include <string>
using std::string;
using namespace std;

class Vertex
{
	int num;
	bool visited;
	list<Vertex>::iterator it;
public:
	Vertex(int num);
	bool operator==(const Vertex& other) const;
	int getNum() const;
	friend class Graph;
	friend class DirectedGraph;
	friend class NonDirectedGraph;
};


#endif _VERTEX_H