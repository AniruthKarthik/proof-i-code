#include <algorithm>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

class DisjointSet {
  public:
	vector<int> parent, rank;

	DisjointSet(int n)
	{
		parent.resize(n);
		rank.resize(n, 0);
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
		}
	}

	int findParent(int node)
	{
		if (node == parent[node])
		{
			return node;
		}
		return parent[node] = findParent(parent[node]);
	}
	void unionByRank(int u, int v)
	{
		int pu = findParent(u);
		int pv = findParent(v);
		if (pu == pv)
			return;

		if (rank[pu] < rank[pv])
			parent[pv] = pv;
		else if (rank[pv] < rank[pu])
			parent[pv] = pu;
		else
		{
			parent[pv] = pu;
			rank[pu]++;
		}
	}
};
class Sol {
  public:
	int spanningTree(int v, vector<vector<int>> adj[])
	{
		vector<pair<int, pair<int, int>>> edges;

		for (int u = 0; u < v; u++)
		{
			for (auto it : adj[u])
			{
				int v = it[0];
				int wt = it[1];
				edges.push_back({wt, {u, v}});
			}
		}

		sort(edges.begin(), edges.end());

		DisjointSet ds(v);
		int sum = 0;

		for (auto it : edges)
		{
			int wt = it.first;
			int u = it.second.first;
			int v = it.second.second;

			if (ds.findParent(u) != ds.findParent(v))
			{
				sum += wt;
				ds.unionByRank(u, v);
			}
		}
		return sum;
	}
};
int main()
{
	int V = 5;
	vector<vector<int>> adj[V];

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

	Sol obj;
	cout << "Total weight of MST (Kruskal) = " << obj.spanningTree(V, adj)
	     << endl;

	return 0;
}
