#include "graphs.hpp"
#include <iostream>
using namespace std;
int main()
{
	Graph g(5, false);

	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	g.display();

	cout << "\nBFS and DFS Traversals:\n";
	g.BFS(0);
	g.DFS(0);

	cout << "\nEdges: " << g.edgeCount() << ", Vertices: " << g.vertexCount()
	     << "\n";

	return 0;
}
