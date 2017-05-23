#include "node.hpp"

namespace doubly {

Node *SortedInsert(Node *head, int data) {
  Node *next = new Node();
  next->data = data;
  next->next = next->prev = nullptr;
  if (head == nullptr) {
    return next;
  }
  if (head->data >= data) {
    next->next = head;
    head->prev = next;
    return next;
  }
  Node *cursor = head;
  while (cursor->next != nullptr and cursor->next->data < data) {
    cursor = cursor->next;
  }
  next->next = cursor->next;
  cursor->next = next;
  next->prev = cursor;
  return head;
}

}
