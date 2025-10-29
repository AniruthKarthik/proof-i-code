#include "tree.hpp"
#include <algorithm>

class AVL {
public:
    static Node<int>* insert(Node<int>* root, int val);
    static Node<int>* deleteNode(Node<int>* root, int val);
    static Node<int>* right_rotate(Node<int>* node);
    static Node<int>* left_rotate(Node<int>* node);

private:
    static int get_height(Node<int>* node);
    static int get_balance(Node<int>* node);
    static Node<int>* balanceTree(Node<int>* node);
    static Node<int>* minValueNode(Node<int>* node);
};
