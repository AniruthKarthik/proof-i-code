#include <algorithm>
using namespace std;

struct Node
{
	int val;
	Node *left;
	Node *right;
	int height;
	Node(int k) : val(k), left(nullptr), right(nullptr), height(0) {};
};

class AVL {
  private:
	Node *root;

	static int get_height(Node *node)
	{
		if (node == nullptr)
		{
			return -1;
		}
		return node->height;
	}

	static int get_balance(Node *node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		return get_height(node->left) - get_height(node->right);
	}

	static Node *left_rotate(Node *node)
	{
		Node *newroot = node->right;
		Node *temp = newroot->left;

		newroot->left = node;
		node->right = temp;

		newroot->height =
		    1 + std::max(get_height(newroot->left), get_height(newroot->right));
		node->height =
		    1 + std::max(get_height(node->left), get_height(node->right));

		return newroot;
	}

	static Node *rightRotate(Node *node)
	{
		Node *newroot = node->left;
		Node *temp = newroot->right;

		newroot->right = node;
		node->left = temp;

		newroot->height =
		    1 + std::max(get_height(newroot->left), get_height(newroot->right));
		node->height =
		    1 + std::max(get_height(node->left), get_height(node->right));

		return newroot;
	}

	static Node *balanceTree(Node *node)
	{
		if (!node)
			return nullptr;

		node->left = balanceTree(node->left);
		node->right = balanceTree(node->right);

		node->height =
		    1 + max(AVL::get_height(node->left), AVL::get_height(node->right));

		int bf = AVL::get_balance(node);

		if (bf > 1)
		{
			if (AVL::get_balance(node->left) < 0)
			{
				node->left = AVL::left_rotate(node->left);
			}
			return AVL::right_rotate(node);
		}
		if (bf < -1)
		{
			if (AVL::get_balance(node->right) > 0)
			{
				node->right = AVL::right_rotate(node->right);
			}
			return AVL::left_rotate(node);
		}

		return node;
	}

	static Node *_insert(Node *node, int val)
	{
		if (node == nullptr)
		{
			return new Node(val);
		}

		if (val < node->val)
		{
			node->left = _insert(node->left, val);
		}
		else if (val > node->val)
		{
			node->right = _insert(node->right, val);
		}
		else
		{
			return node;
		}

		node->height =
		    1 + std::max(get_height(node->left), get_height(node->right));

		return balanceTree(node);
	}

	static Node *minValueNode(Node *node)
	{
		Node *current = node;
		while (current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}

	static Node *_deleteNode(Node *node, int val)
	{
		if (node == nullptr)
		{
			return node;
		}

		if (val < node->val)
		{
			node->left = _deleteNode(node->left, val);
		}
		else if (val > node->val)
		{
			node->right = _deleteNode(node->right, val);
		}
		else
		{
			if ((node->left == nullptr) || (node->right == nullptr))
			{
				Node *temp = node->left ? node->left : node->right;

				if (temp == nullptr)
				{
					temp = node;
					node = nullptr;
				}
				else
				{
					*node = *temp;
				}
				delete temp;
			}
			else
			{
				Node *temp = minValueNode(node->right);

				node->val = temp->val;

				node->right = _deleteNode(node->right, temp->val);
			}
		}

		if (node == nullptr)
		{
			return node;
		}

		node->height =
		    1 + std::max(get_height(node->left), get_height(node->right));

		return balanceTree(node);
	}

  public:
	static Node *right_rotate(Node *node) { return rightRotate(node); }
	static Node *balance(Node *node) { return balanceTree(node); }
	static Node *insert(Node *root, int val) { return _insert(root, val); }
	static Node *deleteNode(Node *root, int val)
	{
		return _deleteNode(root, val);
	}
};
