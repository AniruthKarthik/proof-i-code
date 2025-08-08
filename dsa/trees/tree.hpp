#include <string>
#pragma once
using namespace std;

class Node {
  public:
	char val;
	Node *left;
	Node *right;

	Node(char x) : val(x), left(nullptr), right(nullptr) {}
};

class Tree {
  private:
	Node *root;

	string inorder(Node *node)
	{
		if (!node)
			return "";
		return inorder(node->left) + node->val + inorder(node->right);
	}

	string preorder(Node *node)
	{
		if (!node)
			return "";
		return node->val + preorder(node->left) + preorder(node->right);
	}

	Node *build(const string &preorder, int &preIndex, const string &inorder,
	            int inStart, int inEnd)
	{
		if (inStart > inEnd)
			return nullptr;

		char rootVal = preorder[preIndex++];
		Node *node = new Node(rootVal);

		int inIndex = inorder.find(rootVal, inStart);
		node->left = build(preorder, preIndex, inorder, inStart, inIndex - 1);
		node->right = build(preorder, preIndex, inorder, inIndex + 1, inEnd);

		return node;
	}

  public:
	void build_tree(const string &preorderStr, const string &inorderStr)
	{
		int preIndex = 0;
		root =
		    build(preorderStr, preIndex, inorderStr, 0, inorderStr.size() - 1);
	}

	string get_preorder() { return preorder(root); }

	string get_inorder() { return inorder(root); }
};
