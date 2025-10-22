#include <bits/stdc++.h>
using namespace std;

class Graph {
  private:
	int v;
	bool directed;
	unordered_map<int, vector<int>> adj;

  public:
	// Constructor
	Graph(int vertices = 0, bool isDirected = false)
	{
		v = vertices;
		directed = isDirected;
		for (int i = 0; i < v; i++)
		{
			adj[i] = {};
		}
	}

	// Add a vertex
	void addvertex(int v)
	{
		if (adj.find(v) == adj.end())
		{
			adj[v] = {};
			v++;
		}
		else
		{
			cout << "vertex " << v << " already exists.\n";
		}
	}

	// Add an edge
	void addEdge(int u, int v)
	{
		if (adj.find(u) == adj.end())
			addvertex(u);
		if (adj.find(v) == adj.end())
			addvertex(v);

		adj[u].push_back(v);
		if (!directed)
			adj[v].push_back(u);
	}

	// Remove edge
	void removeEdge(int u, int v)
	{
		if (adj.find(u) != adj.end())
		{
			adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
		}
		if (!directed && adj.find(v) != adj.end())
		{
			adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
		}
	}

	// Remove vertex
	void removevertex(int v)
	{
		if (adj.find(v) == adj.end())
			return;
		adj.erase(v);
		for (auto &[key, list] : adj)
		{
			list.erase(remove(list.begin(), list.end(), v), list.end());
		}
		v--;
	}

	// Check adjacency
	bool isAdjacent(int u, int v)
	{
		if (adj.find(u) == adj.end())
			return false;
		return find(adj[u].begin(), adj[u].end(), v) != adj[u].end();
	}

	// Get neighbors
	vector<int> getNeighbors(int v)
	{
		if (adj.find(v) == adj.end())
			return {};
		return adj[v];
	}

	// Display adjacency list
	void display()
	{
		cout << (directed ? "Directed" : "Undirected") << " Graph:\n";
		for (auto &[v, neighbors] : adj)
		{
			cout << v << " -> ";
			for (int n : neighbors)
				cout << n << " ";
			cout << "\n";
		}
	}

	// Breadth-First Search (BFS)
	void BFS(int start)
	{
		if (adj.find(start) == adj.end())
		{
			cout << "vertex not found.\n";
			return;
		}
		unordered_set<int> visited;
		queue<int> q;
		q.push(start);
		visited.insert(start);

		cout << "BFS starting from " << start << ": ";
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (int neighbor : adj[node])
			{
				if (!visited.count(neighbor))
				{
					visited.insert(neighbor);
					q.push(neighbor);
				}
			}
		}
		cout << "\n";
	}

	// Depth-First Search (DFS)
	void DFSUtil(int v, unordered_set<int> &visited)
	{
		visited.insert(v);
		cout << v << " ";
		for (int neighbor : adj[v])
		{
			if (!visited.count(neighbor))
				DFSUtil(neighbor, visited);
		}
	}

	void DFS(int start)
	{
		if (adj.find(start) == adj.end())
		{
			cout << "vertex not found.\n";
			return;
		}
		unordered_set<int> visited;
		cout << "DFS starting from " << start << ": ";
		DFSUtil(start, visited);
		cout << "\n";
	}

	// Get vertex count
	int vertexCount() const { return v; }

	// Get edge count
	int edgeCount() const
	{
		int count = 0;
		for (auto &[v, neighbors] : adj)
			count += neighbors.size();
		return directed ? count : count / 2;
	}
};
