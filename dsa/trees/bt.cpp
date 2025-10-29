#include "bt.hpp"
#include <iostream>
#include <vector>

using namespace std;

Node<char>* BT::get_root() {
    return root;
}

void BT::set_root(Node<char>* node) {
    root = node;
}

Node<char>* BT::pre_in_build_tree(const string& preOrder, int& preIndex, const string& inOrder, int inStart, int inEnd) {
    if (inStart > inEnd) return nullptr;
    char rootval = preOrder[preIndex++];
    Node<char>* node = new Node<char>(rootval);
    int inIndex = inOrder.find(rootval, inStart);
    node->left = pre_in_build_tree(preOrder, preIndex, inOrder, inStart, inIndex - 1);
    node->right = pre_in_build_tree(preOrder, preIndex, inOrder, inIndex + 1, inEnd);
    return node;
}

Node<char>* BT::post_in_build_tree(const string& postOrder, int& postIndex, const string& inOrder, int inStart, int inEnd) {
    if (inStart > inEnd) return nullptr;
    char rootval = postOrder[postIndex--];
    Node<char>* node = new Node<char>(rootval);
    int inIndex = inOrder.find(rootval, inStart);
    node->right = post_in_build_tree(postOrder, postIndex, inOrder, inIndex + 1, inEnd);
    node->left = post_in_build_tree(postOrder, postIndex, inOrder, inStart, inIndex - 1);
    return node;
}

string BT::get_inOrder(Node<char>* node) {
    if (!node) return "";
    return get_inOrder(node->left) + node->val + get_inOrder(node->right);
}

string BT::get_preOrder(Node<char>* node) {
    if (!node) return "";
    return node->val + get_preOrder(node->left) + get_preOrder(node->right);
}

string BT::get_postOrder(Node<char>* node) {
    if (!node) return "";
    return get_postOrder(node->left) + get_postOrder(node->right) + node->val;
}

string BT::get_levelOrder(Node<char>* node) {
    if (!node) return "";
    queue<Node<char>*> q;
    q.push(node);
    string result;
    while (!q.empty()) {
        Node<char>* current = q.front();
        q.pop();
        result += current->val;
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return result;
}

int BT::get_height(Node<char>* head) {
    if (!head) return 0;
    return 1 + max(get_height(head->left), get_height(head->right));
}

void BT::fillGrid(Node<char>* node, vector<vector<char>>& grid, int level, int left, int right, int maxHeight) {
    if (!node || level >= maxHeight) return;
    int mid = (left + right) / 2;
    int row = level * 2;
    grid[row][mid] = node->val;
    if (node->left || node->right) {
        if (node->left) {
            int leftMid = (left + mid - 1) / 2;
            grid[row + 1][leftMid] = '/';
            fillGrid(node->left, grid, level + 1, left, mid - 1, maxHeight);
        }
        if (node->right) {
            int rightMid = (mid + 1 + right) / 2;
            grid[row + 1][rightMid] = '\\';
            fillGrid(node->right, grid, level + 1, mid + 1, right, maxHeight);
        }
    }
}

void BT::draw() {
    if (!root) {
        cout << "Empty tree\n";
        return;
    }
    int h = height();
    int width = (1 << h) - 1;
    vector<vector<char>> grid(2 * h - 1, vector<char>(width, ' '));
    fillGrid(root, grid, 0, 0, width - 1, h);
    for (int i = 0; i < 2 * h - 1; i++) {
        int lastChar = width - 1;
        while (lastChar >= 0 && grid[i][lastChar] == ' ')
            lastChar--;
        for (int j = 0; j <= lastChar; j++)
            cout << grid[i][j];
        cout << "\n";
    }
}

void BT::pre_in_build(const string& preOrder_str, const string& inOrder_str) {
    int preIndex = 0;
    root = pre_in_build_tree(preOrder_str, preIndex, inOrder_str, 0, inOrder_str.size() - 1);
}

void BT::post_in_build(const string& postOrder_str, const string& inOrder_str) {
    int postIndex = postOrder_str.size() - 1;
    root = post_in_build_tree(postOrder_str, postIndex, inOrder_str, 0, inOrder_str.size() - 1);
}

string BT::preOrder() { return get_preOrder(root); }
string BT::inOrder() { return get_inOrder(root); }
string BT::levelOrder() { return get_levelOrder(root); }
string BT::postOrder() { return get_postOrder(root); }
int BT::height() { return get_height(root); }

int main() {
    BT t;
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