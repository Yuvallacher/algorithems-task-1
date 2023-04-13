#include <iostream>
#include "DirectedGraph.h"
#include "NonDirectedGraph.h"
#pragma warning (disable: 4996)
using std::cin;
using std::cout;
using std::endl;

int main()
{
	try
	{
		int n, m;
		int u, v;
		char directed;
		cout << "Is the graph directed: y/n ";
		cin >> directed >> n >> m;	
		Graph* g;
	
		if (directed == 'y')
			g = new DirectedGraph(n, m);
		else if (directed == 'n')
			g = new NonDirectedGraph(n, m);
		else 
			throw "invalid input";

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

		if (DG)
		{
			if (DG->isAulerian())
			{
				list<Vertex> eulerCircuit = DG->euler();
				cout << "The graph is aulerian\n";
				DG->printEulerCircuit(eulerCircuit);
			}
			else
				cout << "The graph is not aulerian\n";
		}
		else
		{
			if (NDG->isAulerian())
			{
				list<Vertex> eulerCircuit = NDG->euler();
				cout << "The graph is aulerian\n";
				NDG->printEulerCircuit(eulerCircuit);
			}
			else
				cout << "The graph is not aulerian\n";
		}
		if (DG)
			delete(DG);
		else
			delete(NDG);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}