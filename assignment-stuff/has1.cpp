#include <iostream>
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

Node *findlca(Node *root, int a, int b)
{
	if (!root)
		return nullptr;

	if (a < root->val && b < root->val)
	{
		return findlca(root->left, a, b);
	}

	if (a > root->val && b > root->val)
	{
		return findlca(root->right, a, b);
	}
	return root;
}
