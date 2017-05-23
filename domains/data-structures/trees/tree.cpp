#include <iostream>
#include <deque>
#include "tree.hpp"

void preOrder(node *root) {
  if (root != nullptr) {
    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(node *root) {
  if (root != nullptr) {
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
  }
}

void inOrder(node *root) {
  if (root != nullptr) {
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
  }
}

int height(Node *root) {
  if (root == nullptr or (root->left == nullptr and root->right == nullptr)) {
    return 0;
  }
  return 1 + std::max(height(root->left), height(root->right));
}

static void top_view_left(node *root) {
  if (root != nullptr) {
    top_view_left(root->left);
    std::cout << root->data << " ";
  }
}

void top_view(node *root) {
  if (root != nullptr) {
    top_view_left(root->left);
    while (root != nullptr) {
      std::cout << root->data << " ";
      root = root->right;
    }
  }
}

void LevelOrder(node *root) {
  if (root == nullptr)
    return;
  std::deque<node *> deque{root};
  while (deque.size() != 0) {
    node *current = deque.front();
    deque.pop_front();
    std::cout << current->data << " ";
    if (current->left != nullptr) {
      deque.push_back(current->left);
    }
    if (current->right != nullptr) {
      deque.push_back(current->right);
    }
  }
}

void set_note(node **ptr, int value) {
  node *leaf = new node();
  leaf->data = value;
  leaf->left = leaf->right = nullptr;
  *ptr = leaf;
}

node *insert(node *root, int value) {
  if (root == nullptr) {
    set_note(&root, value);
  } else {
    node **ptr = (value < root->data) ? &(root->left) : &(root->right);
    if (*ptr == nullptr) {
      set_note(ptr, value);
    } else {
      insert(*ptr, value);
    }
  }
  return root;
}
