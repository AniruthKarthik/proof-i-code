#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
	unordered_map<int, unordered_map<int, int>> adj;

  public:
	void insertNode(int u)
	{
		if (adj.find(u) == adj.end())
			adj[u] = unordered_map<int, int>();
	}

	void deleteNode(int u)
	{
		adj.erase(u);
		for (auto &[node, neighbors] : adj)
		{
			neighbors.erase(u);
		}
	}

	void insertEdge(int u, int v, int weight = 1)
	{
		insertNode(u);
		insertNode(v);
		adj[u][v] = weight;
	}

	void deleteEdge(int u, int v)
	{
		if (adj.find(u) != adj.end())
			adj[u].erase(v);
	}

	bool areNodesAdjacent(int u, int v)
	{
		return adj.find(u) != adj.end() && adj[u].find(v) != adj[u].end();
	}

	bool areEdgesAdjacent(pair<int, int> e1, pair<int, int> e2)
	{
		return e1.first == e2.first || e1.first == e2.second ||
		       e1.second == e2.first || e1.second == e2.second;
	}

	vector<vector<int>> adjacencyMatrix()
	{
		vector<int> nodes;
		unordered_map<int, int> idxMap;
		int i = 0;
		for (auto &[node, _] : adj)
		{
			nodes.push_back(node);
			idxMap[node] = i++;
		}

		int n = nodes.size();
		vector<vector<int>> mat(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			int u = nodes[i];
			for (auto &[v, w] : adj[u])
			{
				mat[i][idxMap[v]] = w;
			}
		}
		return mat;
	}

	int edgeWeight(int u, int v)
	{
		if (areNodesAdjacent(u, v))
			return adj[u][v];
		return -1;
	}

	vector<int> neighbours(int u)
	{
		vector<int> nbrs;
		if (adj.find(u) != adj.end())
		{
			for (auto &[v, _] : adj[u])
				nbrs.push_back(v);
		}
		return nbrs;
	}

	int degree(int u)
	{
		if (adj.find(u) != adj.end())
			return adj[u].size();
		return 0;
	}

	void display()
	{
		for (auto &[u, neighbors] : adj)
		{
			cout << u << ": ";
			for (auto &[v, w] : neighbors)
				cout << "(" << v << ", w=" << w << ") ";
			cout << endl;
		}
	}
};
int main()
{
	Graph g;

	g.insertNode(1);
	g.insertNode(2);
	g.insertEdge(1, 2, 5);
	g.insertEdge(2, 3, 10);
	g.insertEdge(1, 3, 15);

	cout << "Adjacency List:\n";
	g.display();

	cout << "Are nodes 1 and 2 adjacent? " << g.areNodesAdjacent(1, 2) << endl;
	cout << "Weight of edge (1,3): " << g.edgeWeight(1, 3) << endl;

	cout << "Neighbours of node 2: ";
	for (int n : g.neighbours(2))
		cout << n << " ";
	cout << "\nDegree of node 1: " << g.degree(1) << endl;

	cout << "Adjacency Matrix:\n";
	auto mat = g.adjacencyMatrix();
	for (auto &row : mat)
	{
		for (int val : row)
			cout << val << " ";
		cout << endl;
	}

	return 0;
}
