#pragma once
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
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
	Node *root = nullptr;

	Node *pre_in_build_tree(const string &preOrder, int &preIndex,
	                        const string &inOrder, int inStart, int inEnd)
	{
		if (inStart > inEnd)
			return nullptr;

		char rootval = preOrder[preIndex++];
		Node *node = new Node(rootval);

		int inIndex = inOrder.find(rootval, inStart);
		node->left = pre_in_build_tree(preOrder, preIndex, inOrder, inStart,
		                               inIndex - 1);
		node->right =
		    pre_in_build_tree(preOrder, preIndex, inOrder, inIndex + 1, inEnd);

		return node;
	}

	Node *post_in_build_tree(const string &postOrder, int &postIndex,
	                         const string &inOrder, int inStart, int inEnd)
	{
		if (inStart > inEnd)
			return nullptr;

		char rootval = postOrder[postIndex--];
		Node *node = new Node(rootval);

		int inIndex = inOrder.find(rootval, inStart);
		node->right = post_in_build_tree(postOrder, postIndex, inOrder,
		                                 inIndex + 1, inEnd);
		node->left = post_in_build_tree(postOrder, postIndex, inOrder, inStart,
		                                inIndex - 1);

		return node;
	}

	string get_inOrder(Node *node)
	{
		if (!node)
			return "";
		return get_inOrder(node->left) + node->val + get_inOrder(node->right);
	}

	string get_preOrder(Node *node)
	{
		if (!node)
			return "";
		return node->val + get_preOrder(node->left) + get_preOrder(node->right);
	}

	string get_postOrder(Node *node)
	{
		if (!node)
			return "";
		return get_postOrder(node->left) + get_postOrder(node->right) +
		       node->val;
	}

	string get_levelOrder(Node *node)
	{
		if (!node)
			return "";
		queue<Node *> q;
		q.push(node);

		string result;
		while (!q.empty())
		{
			Node *current = q.front();
			q.pop();

			result += current->val;

			if (current->left)
				q.push(current->left);
			if (current->right)
				q.push(current->right);
		}
		return result;
	}

	int get_height(Node *head)
	{
		if (!head)
			return 0;
		return 1 + max(get_height(head->left), get_height(head->right));
	}

  public:
	// THIS FUNCTION AND THE FOLLOWING DRAW FUNCTION WAS WRIITEN BY CLAUDE
	void fillGrid(Node *node, vector<vector<char>> &grid, int level, int left,
	              int right, int maxHeight)
	{
		if (!node || level >= maxHeight)
			return;
		int mid = (left + right) / 2;
		int row = level * 2;
		grid[row][mid] = node->val;
		if (node->left || node->right)
		{
			if (node->left)
			{
				int leftMid = (left + mid - 1) / 2;
				grid[row + 1][leftMid] = '/';
				fillGrid(node->left, grid, level + 1, left, mid - 1, maxHeight);
			}
			if (node->right)
			{
				int rightMid = (mid + 1 + right) / 2;
				grid[row + 1][rightMid] = '\\';
				fillGrid(node->right, grid, level + 1, mid + 1, right,
				         maxHeight);
			}
		}
	}

	void draw()
	{
		if (!root)
		{
			cout << "Empty tree\n";
			return;
		}
		int h = height();
		int width = (1 << h) - 1; // 2^h - 1
		vector<vector<char>> grid(2 * h - 1, vector<char>(width, ' '));
		fillGrid(root, grid, 0, 0, width - 1, h);
		for (int i = 0; i < 2 * h - 1; i++)
		{
			int lastChar = width - 1;
			while (lastChar >= 0 && grid[i][lastChar] == ' ')
				lastChar--;
			for (int j = 0; j <= lastChar; j++)
				cout << grid[i][j];
			cout << "\n";
		}
	}

	void pre_in_build(const string &preOrder_str, const string &inOrder_str)
	{
		int preIndex = 0;
		root = pre_in_build_tree(preOrder_str, preIndex, inOrder_str, 0,
		                         inOrder_str.size() - 1);
	}

	void post_in_build(const string &postOrder_str, const string &inOrder_str)
	{
		int postIndex = postOrder_str.size() - 1;
		root = post_in_build_tree(postOrder_str, postIndex, inOrder_str, 0,
		                          inOrder_str.size() - 1);
	}

	string preOrder() { return get_preOrder(root); }
	string inOrder() { return get_inOrder(root); }
	string levelOrder() { return get_levelOrder(root); }
	string postOrder() { return get_postOrder(root); }
	int height() { return get_height(root); }
};
