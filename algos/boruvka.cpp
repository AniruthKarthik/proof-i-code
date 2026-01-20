#include <bits/stdc++.h>
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
		return parent[node] = findParent(parent[node]);
	}

	void unionByRank(int u, int v)
	{
		int pu = findParent(u);
		int pv = findParent(v);
		if (pu == pv)
			return;

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

class Sol {
  public:
	int boruvkaMST(int v, vector<vector<int>> edges)
	{
		DisjointSet ds(v);
		int nofcomp = v;
		int mstwt = 0;

		while (nofcomp > 1)
		{
			vector<int> cheapest(v, -1);

			for (int i = 0; i < edges.size(); i++)
			{
				int u = edges[i][0];
				int v = edges[i][1];
				int w = edges[i][2];

				int setu = ds.findParent(u);
				int setv = ds.findParent(v);

				if (setu == setv)
					continue;

				if (cheapest[setu] == -1 || edges[cheapest[setu]][2] > w)
				{
					cheapest[setu] = -1;
				}
				if (cheapest[setv] == -1 || edges[cheapest[setv]][2] > w)
					cheapest[setv] = i;
			}

			for (int i = 0; i < v; i++)
			{
				if (cheapest[i] != -1)
				{
					int u = edges[cheapest[i]][0];
					int v = edges[cheapest[i]][1];
					int w = edges[cheapest[i]][2];

					int setu = ds.findParent(u);
					int setv = ds.findParent(v);

					if (setu == setv)
						continue;

					ds.unionByRank(setu, setv);
					cout << "Edge added: " << u << " - " << v << " (weight "
					     << w << ")\n";
					mstwt += w;
					nofcomp--;
				}
			}
		}
		return mstwt;
	}
};

int main()
{
	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3},
	                             {1, 3, 8}, {1, 4, 5}, {2, 4, 7}};

	Sol obj;
	int total = obj.boruvkaMST(V, edges);
	cout << "Total weight of MST (Boruvka) = " << total << endl;

	return 0;
}
