#include "bst.hpp"
#include <iostream>

using namespace std;

BST::BST() {
    root = NULL;
}

Node<int>* BST::insert(Node<int>* node, int val) {
    if (!node) return new Node<int>(val);
    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    return node;
}

bool BST::search(Node<int>* node, int val) {
    if (!node) return false;
    if (val == node->val) return true;
    if (val < node->val)
        return search(node->left, val);
    else
        return search(node->right, val);
}

void BST::inorder(Node<int>* node) {
    if (!node) return;
    inorder(node->left);
    std::cout << node->val << " ";
    inorder(node->right);
}

Node<int>* BST::findMin(Node<int>* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

Node<int>* BST::remove(Node<int>* node, int val) {
    if (!node) return nullptr;
    if (val < node->val)
        node->left = remove(node->left, val);
    else if (val > node->val)
        node->right = remove(node->right, val);
    else {
        if (!node->right) return node->left;
        if (!node->left) return node->right;
        Node<int>* minright = findMin(node->right);
        node->val = minright->val;
        node->right = remove(node->right, minright->val);
    }
    return node;
}

void BST::insert(int val) { root = insert(root, val); }
bool BST::search(int val) { return search(root, val); }
void BST::inorder() {
    inorder(root);
    cout << endl;
}
void BST::remove(int val) { root = remove(root, val); }

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