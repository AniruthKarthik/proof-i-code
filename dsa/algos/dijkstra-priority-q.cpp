#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int inf = 1e9;
typedef pair<int, int> edge; // dist , vertex

vector<int> dijkstra(int v, vector<edge> adj[], int src)
{
	vector<int> dist(v, inf);
	dist[src] = 0;

	priority_queue<edge, vector<edge>, greater<edge>> pq;
	pq.push({0, src});

	while (!pq.empty())
	{
		int udist = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (udist > dist[u])
			continue;

		for (auto e : adj[u])
		{
			int v = e.first;
			int w = e.second;

			if (dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	return dist;
}
int main()
{
	int V = 5;
	vector<edge> adj[V];

	adj[0].push_back({1, 2});
	adj[0].push_back({3, 6});
	adj[1].push_back({0, 2});
	adj[1].push_back({2, 3});
	adj[1].push_back({3, 8});
	adj[1].push_back({4, 5});
	adj[2].push_back({1, 3});
	adj[2].push_back({4, 7});
	adj[3].push_back({0, 6});
	adj[3].push_back({1, 8});
	adj[4].push_back({1, 5});
	adj[4].push_back({2, 7});

	int src = 0;
	vector<int> dist = dijkstra(V, adj, src);

	cout << "Shortest distances from source " << src << ":\n";
	for (int i = 0; i < V; i++)
		cout << "Vertex " << i << ": " << dist[i] << endl;

	return 0;
}
