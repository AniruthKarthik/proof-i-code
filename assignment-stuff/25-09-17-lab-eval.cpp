#include <climits>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
	    : val(x), left(left), right(right)
	{
	}
};

class Solution {
  public:
	int maxval = INT_MIN;
	void dfs(TreeNode *root, TreeNode *temp)
	{
		if (!temp)
			return;
		dfs(root, temp->left);
		dfs(root, temp->right);
		maxval = max(maxval, abs(root->val - temp->val));

		return;
	}
	int maxAncestorDiff(TreeNode *root)
	{
		if (!root)
			return -1;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode *temp = q.front();
			q.pop();
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
			dfs(temp, temp);
		}
		return maxval;
	}
};
