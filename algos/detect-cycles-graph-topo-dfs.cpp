#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &visited,
         vector<bool> &pathVisited, stack<int> &st)
{
	visited[node] = true;
	pathVisited[node] = true;
	bool hasCycle = false;

	for (int nei : adj[node])
	{
		if (!visited[nei])
			hasCycle = dfs(nei, adj, visited, pathVisited, st);
		else if (pathVisited[nei])
			hasCycle = true;

		if (hasCycle)
			return true; // stop early if found
	}

	pathVisited[node] = false;
	st.push(node);
	return false;
}

bool topologicalSort(int V, vector<int> adj[], vector<int> &topo)
{
	vector<bool> visited(V, false), pathVisited(V, false);
	stack<int> st;

	for (int i = 0; i < V; i++)
		if (!visited[i] && dfs(i, adj, visited, pathVisited, st))
			return false;

	while (!st.empty())
	{
		topo.push_back(st.top());
		st.pop();
	}
	return true;
}

int main()
{
	int V = 6;
	vector<int> adj[V];

	adj[5].push_back(0);
	adj[5].push_back(2);
	adj[4].push_back(0);
	adj[4].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(1);

	vector<int> topo;

	if (topologicalSort(V, adj, topo))
	{
		cout << "Topological Order: ";
		for (int x : topo)
			cout << x << " ";
		cout << endl;
	}
	else
	{
		cout << "Graph has a cycle! Topological sort not possible." << endl;
	}
	return 0;
}
