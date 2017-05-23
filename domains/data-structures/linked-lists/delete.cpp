struct Node {
  int data;
  struct Node *next;
};

Node *Delete(Node *head, int position) {
  if (head == nullptr) {
    return nullptr;
  }
  if (position == 0) {
    return head->next;
  }
  Node *cursor = head;
  for (int i = 0; i < position - 1 and cursor->next != nullptr; ++i) {
    cursor = cursor->next;
  }
  Node *selected = cursor->next;
  cursor->next = cursor->next->next;
  delete selected;
  return head;
}
