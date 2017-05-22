/**
 * https://www.hackerrank.com/challenges/ctci-linked-list-cycle
 * Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.
 */

#include <iostream>
#include <iterator>
#include <initializer_list>

struct Node {
  int data;
  struct Node *next = nullptr;
  static Node *build(std::initializer_list<int> xs) {
    auto size = xs.size();
    Node *p = nullptr, *head = nullptr;
    if (size) {
      head = p = new Node;
      auto curr = std::cbegin(xs);
      for (int i = 0; i < size - 1; ++i) {
        p->data = *curr++;
        p->next = new Node;
        p = p->next;
      }
      p->data = *curr;
    }
    return head;
  }
};

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

int main() {
  auto list = Node::build({1, 2, 3});
  std::cout << std::boolalpha << has_cycle(list) << std::endl;
  auto cycle = Node::build({1, 2, 3});
  cycle->next->next->next = cycle;
  std::cout << std::boolalpha << has_cycle(cycle) << std::endl;
}
