#include "node.hpp"

namespace head {

Node *Insert(Node *head, int data) {
  return new Node{.data = data, .next = head};
}

}
