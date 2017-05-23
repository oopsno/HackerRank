#include "node.hpp"

Node *Node::build(const std::vector<int> &xs) {
  auto size = xs.size();
  Node *p = nullptr, *head = nullptr;
  if (size) {
    head = p = new Node();
    auto curr = std::cbegin(xs);
    for (int i = 0; i < size - 1; ++i) {
      p->data = *curr++;
      p->next = new Node();
      p->next->prev = p;
      p = p->next;
    }
    p->data = *curr;
  }
  return head;
}
