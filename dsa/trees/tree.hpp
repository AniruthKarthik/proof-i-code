#pragma once
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>

template <typename T>
class Node {
public:
    T val;
    Node* left;
    Node* right;
    int height;

    Node(T x) : val(x), left(nullptr), right(nullptr), height(1) {}
};

