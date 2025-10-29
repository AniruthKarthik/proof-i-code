#include "tree.hpp"
#include <iostream>

class BST {
public:
    BST();
    void insert(int val);
    bool search(int val);
    void remove(int val);
    void inorder();

private:
    Node<int>* root;
    Node<int>* insert(Node<int>* node, int val);
    bool search(Node<int>* node, int val);
    Node<int>* remove(Node<int>* node, int val);
    void inorder(Node<int>* node);
    Node<int>* findMin(Node<int>* node);
};
