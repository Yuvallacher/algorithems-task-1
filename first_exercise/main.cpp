#include <iostream>
#include "DirectedGraph.h"
#include "NonDirectedGraph.h"
#pragma warning (disable: 4996)
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n, m;
	int u, v;
	char directed;
	cout << "Is the graph directed: y/n ";
	cin >> directed >> n >> m;
	Graph* g;
	
	if (directed == 'y')
		g = new DirectedGraph(n, m);
	else
		g = new NonDirectedGraph(n, m);
	
	DirectedGraph* DG = dynamic_cast<DirectedGraph*>(g);
	NonDirectedGraph* NDG = dynamic_cast<NonDirectedGraph*>(g);

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		if (DG)
			DG->AddEdge(u, v);
		else
			NDG->AddEdge(u, v);
	}

	if (DG->checkDegrees())
		cout << "even" << endl;
}





