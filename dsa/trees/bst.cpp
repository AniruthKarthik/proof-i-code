#include <iostream>
using namespace std;
#include "bst.hpp"
int main()
{
	BST tree;
	tree.insert(50);
	tree.insert(30);
	tree.insert(70);
	tree.insert(20);
	tree.insert(40);
	tree.insert(60);
	tree.insert(80);

	cout << "Inorder Traversal: ";
	tree.inorder(); // 20 30 40 50 60 70 80

	cout << "Search 40: " << tree.search(40) << endl; // 1 (true)
	cout << "Search 25: " << tree.search(25) << endl; // 0 (false)

	tree.remove(50); // remove root
	cout << "Inorder after removing 50: ";
	tree.inorder(); // 20 30 40 60 70 80

	return 0;
}
