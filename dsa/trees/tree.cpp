#include "tree.hpp"
#include <iostream>
#include <string>
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
	return 0;
}
