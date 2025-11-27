#include <iostream>
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

Node *balance(Node *root)
{
	vector<Node *> nodes;
	inorder(root, nodes);
	return build(nodes, 0, nodes.size() - 1);
}
