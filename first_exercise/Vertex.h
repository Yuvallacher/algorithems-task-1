#ifndef _VERTEX_H
#define _VERTEX_H

#include <string>
using std::string;

class Vertex
{
	int num;
	bool visited;

public:
	Vertex(int num);
	bool operator==(const Vertex& other) const;

	friend class Graph;
	friend class DirectedGraph;
	friend class NonDirectedGraph;
};


#endif _VERTEX_H