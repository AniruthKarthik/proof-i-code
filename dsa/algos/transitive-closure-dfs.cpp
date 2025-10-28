#include <iostream>
using namespace std;

#define V 4
int reach[V][V];

void dfs(int graph[V][V], int u, int v)
{
	reach[u][v] = 1;
	for (int k = 0; k < V; k++)
	{
		if (graph[v][k] && !reach[u][k])
		{
			dfs(graph, u, k);
		}
	}
}

void trans_clos(int graph[V][V], int u, int v)
{
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			if (graph[i][j])
				dfs(graph, i, j);

	cout << "Transitive Closure Matrix:\n";
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
			cout << reach[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int graph[V][V] = {{0, 1, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 1}, {0, 0, 0, 0}};

	trans_clos(graph, 1, 3);
	return 0;
}
