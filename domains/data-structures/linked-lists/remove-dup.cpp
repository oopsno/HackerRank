#include "node.hpp"

Node* RemoveDuplicates(Node *head) {
  int latest;
  Node *cursor;
  if (head == nullptr or head->next == nullptr) {
    return head;
  }
  latest = head->data;
  cursor = head;
  while (cursor->next != nullptr) {
    if (cursor->next->data == latest) {
      cursor->next = cursor->next->next;
      if (cursor->next == nullptr) {
        break;
      }
    } else {
      latest = cursor->next->data;
      cursor = cursor->next;
    }
  }
  return head;
}
