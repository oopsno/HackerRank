#include "node.hpp"

int GetNode(Node *head, int positionFromTail) {
  int length = 0;
  Node *patrol = head;
  while (patrol != nullptr) {
    length += 1;
    patrol = patrol->next;
  }
  patrol = head;
  for (int i = 0; i < length - positionFromTail - 1; ++i) {
    patrol = patrol->next;
  }
  return patrol->data;
}

