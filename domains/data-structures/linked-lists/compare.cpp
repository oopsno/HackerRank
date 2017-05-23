#include "node.hpp"

int CompareLists(Node *headA, Node *headB) {
  if (headA == headB) {
    return true;
  } else if (headA != nullptr and headB != nullptr) {
    return headA->data == headB->data and CompareLists(headA->next, headB->next);
  } else {
    return false;
  }
}

