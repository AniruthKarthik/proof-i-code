#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
	int val;
	Node *left, *right;
	Node(int x)
	{
		val = x;
		left = right = nullptr;
	}
};

void inorder(Node *root, vector<Node *> &nodes)
{
	if (!root)
		return;
	inorder(root->left, nodes);
	nodes.push_back(root);
	inorder(root->right, nodes);
}

Node *build(vector<Node *> &nodes, int start, int end)
{
	if (start > end)
		return nullptr;
	int mid = (start + end) / 2;
	Node *root = nodes[mid];
	root->left = build(nodes, start, mid - 1);
	root->right = build(nodes, mid + 1, end);
	return root;
}
vector<Node *> merge(const vector<Node *> &arr1, const vector<Node *> &arr2)
{
	vector<Node *> merged;
	int i = 0, j = 0;
	int m = arr1.size(), n = arr2.size();

	while (i < m && j < n)
	{
		if (arr1[i]->val < arr2[j]->val)
		{
			merged.push_back(arr1[i++]);
		}
		else
		{
			merged.push_back(arr2[j++]);
		}
	}

	while (i < m)
		merged.push_back(arr1[i++]);
	while (j < n)
		merged.push_back(arr2[j++]);

	return merged;
}

Node *balance(Node *r1, Node *r2)
{
	vector<Node *> ones;
	vector<Node *> twos;
	inorder(r1, ones);
	inorder(r2, twos);
	vector<Node *> nodes = merge(ones, twos);
	return build(nodes, 0, nodes.size() - 1);
}
