#include "Vertex.h"

Vertex::Vertex(int num) : num(num)
{
	visited = false;
}

bool Vertex::operator==(const Vertex& other) const
{
	return num == other.num;
}