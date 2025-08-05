#include <iostream>
#include <ostream>
#include <string>
using namespace std;

template <typename T> class Node {
  public:
	T val;
	Node<T> *left;
	Node<T> *right;

	Node(T x) : val(x), left(nullptr), right(nullptr) {};
};

class Tree {
  private:
	Node<char> *root;

	string inorder(Node<char> *root)
	{
		if (root == nullptr)
			return "";
		return inorder(root->left) + root->val + inorder(root->right);
	}

	string preorder(Node<char> *root)
	{
		if (root == nullptr)
			return "";
		return root->val + preorder(root->left) + preorder(root->right);
	}

  public:
	Node<char> *build(char *&preorder, char *inorder_start, char *inorder_end)
	{
		if (inorder_start >= inorder_end)
			return nullptr;
		char *temp_ptr = inorder_start;
		while (*temp_ptr != *preorder && temp_ptr < inorder_end)
		{
			++temp_ptr;
		}
		Node<char> *root = new Node<char>(*preorder);
		++preorder;
		root->left = build(preorder, inorder_start, temp_ptr);
		root->right = build(preorder, temp_ptr + 1, inorder_end);

		return root;
	}

	void build_tree(string preorder, string inorder)
	{
		char *preorder_ptr = preorder.data();
		char *inorder_ptr = inorder.data();
		char *inorder_end = inorder.data() + inorder.size();
		this->root = build(preorder_ptr, inorder_ptr, inorder_end);
	}

	string get_preorder() { return preorder(this->root); }

	string get_inorder() { return inorder(this->root); }
};

int main()
{
	Tree t;
	string ipreorder = "abdec";
	string iinorder = "dbeac";
	t.build_tree(ipreorder, iinorder);
	cout << "input preorder: " << ipreorder << endl;
	cout << "input inorder: " << iinorder << endl;
	cout << "tree's preorder: " << t.get_preorder() << endl;
	cout << "tree's inorder: " << t.get_inorder() << endl;
}
