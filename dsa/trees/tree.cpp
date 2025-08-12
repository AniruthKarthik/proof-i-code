#include "tree.hpp"
#include <iostream>
#include <string>
int main()
{
	Tree t;
	string ipreorder = "abdec";
	string iinorder = "dbeac";
	t.pre_in_build(ipreorder, iinorder);
	cout << "input preorder: " << ipreorder << endl;
	cout << "input inorder: " << iinorder << endl;
	cout << endl;
	t.draw();
	cout << endl;
	cout << "tree's preorder: " << t.preOrder() << endl;
	cout << "tree's inorder: " << t.inOrder() << endl;
	cout << "tree's level order: " << t.levelOrder() << endl;
	cout << "tree's post order: " << t.postOrder() << endl;
	cout << endl;
	cout << "the height of the tree is " << t.height();
	return 0;
}
