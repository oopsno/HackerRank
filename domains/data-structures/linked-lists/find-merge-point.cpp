#include "node.hpp"

inline int length(Node *head) {
  int result = 0;
  while (head != nullptr) {
    result += 1;
    head = head->next;
  }
  return result;
}

Node *forward(Node *head, int n) {
  for (int i = 0; i < n; ++i) {
    head = head->next;
  }
  return head;
}

int FindMergeNode(Node *headA, Node *headB) {
  const int la = length(headA), lb = length(headB);
  Node *xs, *ys;
  if (la > lb) {
    xs = forward(headA, la - lb);
    ys = headB;
  } else {
    xs = forward(headB, lb - la);
    ys = headA;
  };
  while (xs != ys) {
    xs = xs->next;
    ys = ys->next;
  }
  return xs->data;
}