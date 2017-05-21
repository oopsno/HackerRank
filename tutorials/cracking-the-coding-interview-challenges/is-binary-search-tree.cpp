/**
 * https://www.hackerrank.com/challenges/ctci-is-binary-search-tree
 * Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge.
 * Hint: you may want to write one or more helper functions.  
 * The Node structure is defined as follows:
 */

#include <iostream>
#include <tuple>
#include <string>
#include <algorithm>

struct Node {
    int   data;
    Node* left;
    Node* right;
};

using data_t = decltype(Node::data);

#define MAKE_SELECTOR(name, function)                                    \
template<typename T>                                                     \
struct name {                                                            \
    static T select(const T a, const T b ) { return function(a, b); }    \
}
MAKE_SELECTOR(max, std::max);
MAKE_SELECTOR(min, std::min);
#undef  MAKE_SELECTOR

template<template<typename> class selector>
struct finder {
    static data_t find(Node *root) {
        const data_t data  = root->data;
              data_t left  = data;
              data_t right = data;
        if (root->left != nullptr) {
            left  = selector<data_t>::select(data, find(root->left));
        }
        if (root->right != nullptr) {
            right = selector<data_t>::select(data, find(root->right));
        }
        return selector<data_t>::select(left, right);
    }
};

bool checkBST(Node* root) {
    bool left = true, right = true;
    if (root != nullptr) {
        if (root->left  != nullptr) {
            left  = root->data > finder<max>::find(root->left)  and checkBST(root->left);
        }
        if (root->right != nullptr) {
            right = root->data < finder<min>::find(root->right) and checkBST(root->right);
        }
    }
    return left and right;
}
