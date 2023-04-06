#include "Vertex.h"

int Vertex::verticesCounter = 0;

Vertex::Vertex()
{
	num = verticesCounter++;
	color = "white";
}

Vertex::Vertex(int num) : num(num)
{
	color = "white";
}

bool Vertex::operator==(const Vertex& other) const
{
	return num == other.num;
}