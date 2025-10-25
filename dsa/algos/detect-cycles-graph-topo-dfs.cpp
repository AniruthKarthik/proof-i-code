#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &visited,
         vector<bool> &recStack, stack<int> &st)
{
	visited[node] = true;
	recStack[node] = true;

	for (int neighbor : adj[node])
	{
		if (!visited[neighbor])
		{
			if (dfs(neighbor, adj, visited, recStack, st))
				return true;
		}
		else if (recStack[neighbor])
		{
			return true;
		}
	}

	recStack[node] = false;
	st.push(node);
	return false;
}

bool topologicalSort(int V, vector<int> adj[], vector<int> &topoOrder)
{
	vector<bool> visited(V, false);
	vector<bool> recStack(V, false);
	stack<int> st;

	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			if (dfs(i, adj, visited, recStack, st))
			{
				return false;
			}
		}
	}

	while (!st.empty())
	{
		topoOrder.push_back(st.top());
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
		for (int node : topo)
			cout << node << " ";
		cout << endl;
	}
	else
	{
		cout << "Graph has a cycle! Topological sort not possible." << endl;
	}

	return 0;
}
