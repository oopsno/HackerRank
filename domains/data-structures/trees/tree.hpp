#ifndef HACKERRANK_TREE_HPP
#define HACKERRANK_TREE_HPP

struct node {
  int data;
  node *left;
  node *right;
};

using Node = node;

void preOrder(node *root);
void postOrder(node *root);
void inOrder(node *root);

#endif //HACKERRANK_TREE_HPP
