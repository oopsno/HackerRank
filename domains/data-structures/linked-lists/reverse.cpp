#include "node.hpp"

Node *Reverse(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node *next = head->next;
  Node *rest = next->next;
  head->next = nullptr;
  do {
    rest = next->next;
    next->next = head;
    head = next;
    next = rest;
  } while (rest != nullptr);
  return head;
}
