#include <iostream>
#include <ostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
	visited[node] = true;

	for (int nei : adj[node])
	{
		if (!visited[nei])
		{
			dfs(nei, adj, visited, st);
		}
	}
	st.push(node);
}

vector<int> toposort(int v, vector<int> adj[])
{
	vector<bool> visited(v, false);
	stack<int> st;

	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
		{
			dfs(i, adj, visited, st);
		}
	}

	vector<int> toporder;
	while (!st.empty())
	{
		toporder.push_back(st.top());
		st.pop();
	}
	return toporder;
}

int main(int argc, char *argv[])
{
	int v = 6;
	vector<int> adj[v];
	adj[5].push_back(0);
	adj[5].push_back(2);
	adj[4].push_back(0);
	adj[4].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(1);

	vector<int> topo = toposort(v, adj);

	std::cout << "topological order: ";
	for (int node : topo)
	{
		cout << node << " ";
	}
	cout << endl;

	return 0;
}
