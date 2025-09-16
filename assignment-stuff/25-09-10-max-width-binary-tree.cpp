#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
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
	int widthOfBinaryTree(TreeNode *root)
	{
		if (!root)
			return 0;
		unsigned long long ans = 0;
		queue<pair<TreeNode *, unsigned long long>> q;
		q.push({root, 0});
		while (!q.empty())
		{
			int size = q.size();
			unsigned long long mm = q.front().second;
			unsigned long long first = 0, last = 0;
			for (int i = 0; i < size; i++)
			{
				TreeNode *node = q.front().first;
				unsigned long long curid = q.front().second - mm;
				q.pop();
				if (i == 0)
					first = curid;
				if (i == size - 1)
					last = curid;
				if (node->left)
					q.push({node->left, curid * 2 + 1});
				if (node->right)
					q.push({node->right, curid * 2 + 2});
			}
			ans = max(ans, last - first + 1);
		}
		return static_cast<int>(ans);
	}
};
