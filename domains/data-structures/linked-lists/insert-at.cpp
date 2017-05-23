#include "node.hpp"

Node *InsertNth(Node *head, int data, int position) {
  Node *cursor = head;
  if (head == nullptr) {
    return new Node{.data = data, .next = nullptr};
  }
  if (position == 0) {
    return new Node{.data = data, .next = head};
  }
  for (int i = 0; i < position - 1 and cursor->next != nullptr; ++i) {
    cursor = cursor->next;
  }
  cursor->next = new Node{.data = data, .next = cursor->next };
  return head;
}
