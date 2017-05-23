#include <iostream>

struct Node {
  int data;
  struct Node *next;
};

void ReversePrint(Node *head) {
  if (head != nullptr) {
    ReversePrint(head->next);
    std::cout << head->data << std::endl;
  }
}

