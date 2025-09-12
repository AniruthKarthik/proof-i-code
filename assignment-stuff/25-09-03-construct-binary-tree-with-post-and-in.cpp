#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char val;
	Node *left;
	Node *right;
	Node(char x) : val(x), left(NULL), right(NULL) {}
};

Node *buildTreeHelper(string &preorder, int preStart, int preEnd,
                      string &inorder, int inStart, int inEnd,
                      unordered_map<char, int> &inMap)
{
	if (preStart > preEnd || inStart > inEnd)
		return NULL;

	char rootVal = preorder[preStart];
	Node *root = new Node(rootVal);

	int inRoot = inMap[rootVal];
	int numsLeft = inRoot - inStart;

	root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
	                             inorder, inStart, inRoot - 1, inMap);
	root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
	                              inorder, inRoot + 1, inEnd, inMap);

	return root;
}

Node *buildTree(string preorder, string inorder)
{
	unordered_map<char, int> inMap;
	for (int i = 0; i < inorder.size(); i++)
	{
		inMap[inorder[i]] = i;
	}
	return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0,
	                       inorder.size() - 1, inMap);
}

void printPostorder(Node *root)
{
	if (!root)
		return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->val;
}

int main()
{
	string preorder = "ABDEC";
	string inorder = "DBEAC";

	Node *root = buildTree(preorder, inorder);

	cout << "Postorder traversal of constructed tree:\n";
	printPostorder(root); // Expected output: DEBCA
	cout << endl;

	return 0;
}
