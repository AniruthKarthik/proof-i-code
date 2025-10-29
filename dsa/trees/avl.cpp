#include "avl.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

int AVL::get_height(Node<int>* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
}

int AVL::get_balance(Node<int>* node) {
    if (node == nullptr) {
        return 0;
    }
    return get_height(node->left) - get_height(node->right);
}

Node<int>* AVL::left_rotate(Node<int>* node) {
    Node<int>* newroot = node->right;
    Node<int>* temp = newroot->left;

    newroot->left = node;
    node->right = temp;

    newroot->height = 1 + std::max(get_height(newroot->left), get_height(newroot->right));
    node->height = 1 + std::max(get_height(node->left), get_height(node->right));

    return newroot;
}

Node<int>* AVL::right_rotate(Node<int>* node) {
    Node<int>* newroot = node->left;
    Node<int>* temp = newroot->right;

    newroot->right = node;
    node->left = temp;

    newroot->height = 1 + std::max(get_height(newroot->left), get_height(newroot->right));
    node->height = 1 + std::max(get_height(node->left), get_height(node->right));

    return newroot;
}

Node<int>* AVL::balanceTree(Node<int>* node) {
    if (!node) return nullptr;

    node->left = balanceTree(node->left);
    node->right = balanceTree(node->right);

    node->height = 1 + max(AVL::get_height(node->left), AVL::get_height(node->right));

    int bf = AVL::get_balance(node);

    if (bf > 1) {
        if (AVL::get_balance(node->left) < 0) {
            node->left = AVL::left_rotate(node->left);
        }
        return AVL::right_rotate(node);
    }
    if (bf < -1) {
        if (AVL::get_balance(node->right) > 0) {
            node->right = AVL::right_rotate(node->right);
        }
        return AVL::left_rotate(node);
    }

    return node;
}

Node<int>* AVL::insert(Node<int>* node, int val) {
    if (node == nullptr) {
        return new Node<int>(val);
    }

    if (val < node->val) {
        node->left = insert(node->left, val);
    } else if (val > node->val) {
        node->right = insert(node->right, val);
    } else {
        return node;
    }

    node->height = 1 + std::max(get_height(node->left), get_height(node->right));

    return balanceTree(node);
}

Node<int>* AVL::minValueNode(Node<int>* node) {
    Node<int>* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node<int>* AVL::deleteNode(Node<int>* node, int val) {
    if (node == nullptr) {
        return node;
    }

    if (val < node->val) {
        node->left = deleteNode(node->left, val);
    } else if (val > node->val) {
        node->right = deleteNode(node->right, val);
    } else {
        if ((node->left == nullptr) || (node->right == nullptr)) {
            Node<int>* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            Node<int>* temp = minValueNode(node->right);

            node->val = temp->val;

            node->right = deleteNode(node->right, temp->val);
        }
    }

    if (node == nullptr) {
        return node;
    }

    node->height = 1 + std::max(get_height(node->left), get_height(node->right));

    return balanceTree(node);
}

void preorder(Node<int> *node)
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
	cout << "--- DEMONSTRATION OF NORMAL RIGHT ROTATION ---\\n";
	Node<int> *root_rotation = new Node<int>(20);
	root_rotation->left = new Node<int>(10);
	root_rotation->right = new Node<int>(30);
	root_rotation->left->right = new Node<int>(15);

	cout << "Before right rotation: ";
	preorder(root_rotation);
	cout << "\\n";

	root_rotation = AVL::right_rotate(root_rotation);

	cout << "After right rotation: ";
	preorder(root_rotation);
	cout << "\\n\\n";

	// --- 2. Demonstration of AVL Tree Insertion and Deletion ---
	cout << "--- DEMONSTRATION OF AVL TREE INSERTION AND DELETION ---\\n";
	Node<int> *root_avl = nullptr;

	// Test Insertions
	cout << "Inserting: 50, 30, 70, 20, 40, 60, 80, 10\\n";
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
	cout << "\\n\\n";

	// Test Deletions
	cout << "Deleting 20 (leaf node)\\n";
	root_avl = AVL::deleteNode(root_avl, 20);
	cout << "Tree after deleting 20 (preorder): ";
	preorder(root_avl);
	cout << "\\n\\n";

	cout << "Deleting 70 (node with two children)\\n";
	root_avl = AVL::deleteNode(root_avl, 70);
	cout << "Tree after deleting 70 (preorder): ";
	preorder(root_avl);
	cout << "\\n\\n";

	cout << "Deleting 50 (root node)\\n";
	root_avl = AVL::deleteNode(root_avl, 50);
	cout << "Tree after deleting 50 (preorder): ";
	preorder(root_avl);
	cout << "\\n\\n";

	return 0;
}