/**
 * https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list
 */

#include <iostream>
#include "node.hpp"

void Print(Node *head) {
  while (head != nullptr) {
    std::cout << head->data << std::endl;
    head = head->next;
  }
}
