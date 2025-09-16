#include <iostream>
#include <string>
using namespace std;

class BST {
  private:
	struct Node
	{
		string key;
		int val;
		Node *left;
		Node *right;
		Node(string k, int v)
		    : key(k), val(v), left(nullptr), right(nullptr) {};
	};

	Node *root;

	Node *add(Node *node, string key, int val)
	{
		if (!node)
			return new Node(key, val);
		if (node->key == key)
			node->val = val;
		else if (node->key > key)
			node->left = add(node->left, key, val);
		else if (node->key < key)
			node->right = add(node->right, key, val);
		return node;
	}

	int look(Node *root, string key)
	{
		if (!root)
			return -1;
		else if (root->key < key)
			return look(root->left, key);
		else if (root->key > key)
			return look(root->right, key);
		return root->val;
	}

	Node *remove(Node *root, string key)
	{
		if (!root)
			return nullptr;
		if (key < root->key)
		{
			root->left = remove(root->left, key);
		}
		else if (key > root->key)
		{
			root->right = remove(root->right, key);
		}
		else
		{
			if (!root->right)
			{
				return root->left;
			}
			else if (!root->left)
			{
				return root->right;
			}

			Node *suc = root->right;
			while (suc->left)
			{
				suc = suc->left;
			}
			root->key = suc->key;
			root->val = suc->val;
			root->right = remove(root->right, suc->key);
		}
		return root;
	}

	void inorder(Node *root)
	{
		if (!root)
			return;
		inorder(root->left);
		cout << root->key << " - " << root->val << endl;
		inorder(root->right);
	}

  public:
	BST() : root(nullptr) {};

	void add(string key, int val) { root = add(root, key, val); }
	void remove(string key) { root = remove(root, key); }
	int look(string key) { return look(root, key); }
	void inorder() { inorder(root); }
};

int main()
{
	BST t;
	t.add("banana", 12);
	t.add("apple", 42);
	t.add("orange", 25);

	t.inorder();
	cout << endl;

	t.remove("apple");

	t.inorder();
	cout << endl;

	return 0;
}
