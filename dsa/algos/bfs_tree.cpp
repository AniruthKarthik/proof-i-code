#include "tree.hpp"
#include <iostream>
#include <queue>

template <typename T>
void bfs(Node<T>* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node<T>*> q;
    q.push(root);

    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        std::cout << current->val << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {
    Node<int>* root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);
    root->left->left = new Node<int>(4);
    root->left->right = new Node<int>(5);

    std::cout << "BFS traversal: ";
    bfs(root);
    std::cout << std::endl;

    return 0;
}
