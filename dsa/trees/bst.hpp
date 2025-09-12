#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *left;
	Node *right;
	Node(int x) : val(x), left(nullptr), right(nullptr) {};
};

class BST {
  private:
	Node *root;

	Node *insert(Node *node, int val)
	{
		if (!node)
			return new Node(val);
		if (val < node->val)
			node->left = insert(node->left, val);
		else if (val > node->val)
			node->right = insert(node->right, val);
		return node;
	}

	bool search(Node *node, int val)
	{
		if (!node)
			return false;
		if (val == node->val)
			return true;
		if (val < node->val)
			return search(node->left, val);
		else
			return search(node->right, val);
	}

	void inorder(Node *node)
	{
		if (!node)
			return;
		inorder(node->left);
		std::cout << node->val << " ";
		inorder(node->right);
	}
	Node *findMin(Node *node)
	{
		while (node && node->left)
		{
			node = node->left;
		}
		return node;
	}
	Node *remove(Node *node, int val)
	{
		if (!node)
			return nullptr;
		if (val < node->val)
			node->left = remove(node->left, val);
		else if (val > node->val)
			node->right = remove(node->right, val);
		else
		{
			if (!node->right)
				return node->left;
			if (!node->left)
				return node->right;
			Node *minright = findMin(node->right);
			node->val = minright->val;
			node->right = remove(node->right, minright->val);
		}
		return node;
	}

  public:
	BST() { root = NULL; }

	void insert(int val) { root = insert(root, val); }
	bool search(int val) { return search(root, val); }
	void inorder()
	{
		inorder(root);
		cout << endl;
	}
	void remove(int val) { root = remove(root, val); }
};
