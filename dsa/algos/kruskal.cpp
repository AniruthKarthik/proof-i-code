#include <algorithm>
#include <iostream>
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
			parent[i] = i;
	}

	int findParent(int node)
	{
		if (node == parent[node])
			return node;
		return parent[node] = findParent(parent[node]); // path compression
	}

	void unionByRank(int u, int v)
	{
		int pu = findParent(u);
		int pv = findParent(v);
		if (pu == pv)
			return; // already in same set

		if (rank[pu] < rank[pv])
			parent[pu] = pv;
		else if (rank[pv] < rank[pu])
			parent[pv] = pu;
		else
		{
			parent[pv] = pu;
			rank[pu]++;
		}
	}
};

class Solution {
  public:
	int spanningTree(int V, vector<pair<int, int>> adj[])
	{
		vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}

		for (int u = 0; u < V; u++)
		{
			for (auto it : adj[u])
			{
				int v = it.first;
				int wt = it.second;
				edges.push_back({wt, {u, v}});
			}
		}

		sort(edges.begin(), edges.end());

		DisjointSet ds(V);
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
	vector<pair<int, int>> adj[V]; // index - src {dest, weight}

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

	Solution obj;
	cout << "Total weight of MST (Kruskal) = " << obj.spanningTree(V, adj)
	     << endl;

	return 0;
}
