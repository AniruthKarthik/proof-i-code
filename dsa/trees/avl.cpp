#include "avl.hpp"
#include <ios>
#include <iostream>
using namespace std;

void preorder(Node *node)
{
	if (!node)
	{
		cout << "null" << " ";
		return;
	}

	cout << node->val << " ";
	preorder(node->left);
	preorder(node->right);
}

int main()
{
	// --- 1. Demonstration of Normal Right Rotation ---
	cout << "--- DEMONSTRATION OF NORMAL RIGHT ROTATION ---\n";
	Node *root_rotation = new Node(20);
	root_rotation->left = new Node(10);
	root_rotation->right = new Node(30);
	root_rotation->left->right = new Node(15);

	cout << "Before right rotation: ";
	preorder(root_rotation);
	cout << "\n";

	root_rotation = AVL::right_rotate(root_rotation);

	cout << "After right rotation: ";
	preorder(root_rotation);
	cout << "\n\n";

	// --- 2. Demonstration of AVL Tree Insertion and Deletion ---
	cout << "--- DEMONSTRATION OF AVL TREE INSERTION AND DELETION ---\n";
	Node *root_avl = nullptr;

	// Test Insertions
	cout << "Inserting: 50, 30, 70, 20, 40, 60, 80, 10\n";
	root_avl = AVL::insert(root_avl, 50);
	root_avl = AVL::insert(root_avl, 30);
	root_avl = AVL::insert(root_avl, 70);
	root_avl = AVL::insert(root_avl, 20);
	root_avl = AVL::insert(root_avl, 40);
	root_avl = AVL::insert(root_avl, 60);
	root_avl = AVL::insert(root_avl, 80);
	root_avl = AVL::insert(root_avl, 10);

	cout << "Tree after insertions (preorder): ";
	preorder(root_avl);
	cout << "\n\n";

	// Test Deletions
	cout << "Deleting 20 (leaf node)\n";
	root_avl = AVL::deleteNode(root_avl, 20);
	cout << "Tree after deleting 20 (preorder): ";
	preorder(root_avl);
	cout << "\n\n";

	cout << "Deleting 70 (node with two children)\n";
	root_avl = AVL::deleteNode(root_avl, 70);
	cout << "Tree after deleting 70 (preorder): ";
	preorder(root_avl);
	cout << "\n\n";

	cout << "Deleting 50 (root node)\n";
	root_avl = AVL::deleteNode(root_avl, 50);
	cout << "Tree after deleting 50 (preorder): ";
	preorder(root_avl);
	cout << "\n\n";

	return 0;
}
