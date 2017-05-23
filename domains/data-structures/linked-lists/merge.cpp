#include "node.hpp"

Node *MergeLists(Node *headA, Node *headB) {
  Node *merged = nullptr;
  Node *cursor = nullptr;
  Node *selected = nullptr;
  while (headA != nullptr and headB != nullptr) {
    if (headA->data < headB->data) {
      selected = headA;
      headA = headA->next;
    } else {
      selected = headB;
      headB = headB->next;
    }
    if (merged == nullptr) {
      merged = selected;
      cursor = selected;
    } else {
      cursor->next = selected;
      cursor = cursor->next;
    }
  }
  if (merged == nullptr) {
    return headA == nullptr ? headB : headA;
  }
  if (headA != nullptr) {
    cursor->next = headA;
  } else {
    cursor->next = headB;
  }
  return merged;
}

