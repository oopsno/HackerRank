#ifndef HACKERRANK_LINKED_LIST_HPP
#define HACKERRANK_LINKED_LIST_HPP

#include <vector>

struct Node {
  int data;
  Node *next, *prev;
  static Node *build(const std::vector<int> &xs);
};

void Print(Node *head);
namespace head { Node *Insert(Node *head, int data); }
namespace tail { Node *Insert(Node *head, int data); }
Node *InsertNth(Node *head, int data, int position);
Node *Delete(Node *head, int position);
void ReversePrint(Node *head);
Node *Reverse(Node *head);
int CompareLists(Node *headA, Node *headB);
Node *MergeLists(Node *headA, Node *headB);
int GetNode(Node *head, int positionFromTail);
Node* RemoveDuplicates(Node *head);
bool has_cycle(Node* head);
int FindMergeNode(Node *headA, Node *headB);
namespace doubly {

Node* SortedInsert(Node *head,int data);
Node* Reverse(Node* head);

}

#endif //HACKERRANK_LINKED_LIST_HPP
