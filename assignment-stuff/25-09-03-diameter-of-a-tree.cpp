#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(Node *node)
{
	if (!node)
		return 0;
	return 1 + max(height(node->right), height(node->left));
}

int diameter(Node *root)
{
	if (!root)
		return 0;
	int rootheight = height(root->left) + height(root->right);
	int lefttree = diameter(root->left);
	int righttree = diameter(root->right);

	return max({rootheight, lefttree, righttree});
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->right = new Node(6);
	root->left->left->left = new Node(7);

	cout << "Diameter of the tree is: " << diameter(root) << endl;

	return 0;
}
