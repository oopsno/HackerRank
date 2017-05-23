#include "node.hpp"

namespace tail {

Node *Insert(Node *head, int data) {
  Node *last = new Node{.data = data, .next = nullptr};
  if (head == nullptr) {
    return last;
  }
  Node *tail = head;
  while (tail->next != nullptr) {
    tail = tail->next;
  }
  tail->next = last;
  return head;
}

}
