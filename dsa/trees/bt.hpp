
#pragma once
#include "tree.hpp"

class BT {
public:
    Node<char>* get_root();
    void set_root(Node<char>* node);
    void pre_in_build(const std::string& preOrder, const std::string& inOrder);
    void post_in_build(const std::string& postOrder, const std::string& inOrder);
    std::string preOrder();
    std::string inOrder();
    std::string postOrder();
    std::string levelOrder();
    int height();
    void draw();

private:
    Node<char>* root = nullptr;
    Node<char>* pre_in_build_tree(const std::string& preOrder, int& preIndex, const std::string& inOrder, int inStart, int inEnd);
    Node<char>* post_in_build_tree(const std::string& postOrder, int& postIndex, const std::string& inOrder, int inStart, int inEnd);
    std::string get_inOrder(Node<char>* node);
    std::string get_preOrder(Node<char>* node);
    std::string get_postOrder(Node<char>* node);
    std::string get_levelOrder(Node<char>* node);
    int get_height(Node<char>* head);
    void fillGrid(Node<char>* node, std::vector<std::vector<char>>& grid, int level, int left, int right, int maxHeight);
};
