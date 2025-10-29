#include "tree.hpp"
#include <iostream>
#include <vector>

template <typename T>
void preOrder(Node<T>* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

template <typename T>
void inOrder(Node<T>* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    std::cout << root->val << " ";
    inOrder(root->right);
}

template <typename T>
void postOrder(Node<T>* root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->val << " ";
}

int main() {
    Node<int>* root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);
    root->left->left = new Node<int>(4);
    root->left->right = new Node<int>(5);

    std::cout << "Pre-order traversal: ";
    preOrder(root);
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    postOrder(root);
    std::cout << std::endl;

    return 0;
}
