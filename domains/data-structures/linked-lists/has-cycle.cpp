#include "node.hpp"

inline Node *next(Node *p) {
  return p == nullptr ? nullptr : p->next;
}

bool has_cycle(Node *head) {
  Node *p1 = head, *p2 = head;
  do {
    p1 = next(p1);
    p2 = next(next(p2));
    if (p1 == nullptr or p2 == nullptr) {
      return false;
    }
  } while (p1 != p2);
  return true;
}
