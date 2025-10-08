#include <iostream>

// use std::forward_list instead of implementing

class Node {
 public:
  int value;
  Node *next;

  Node(int val) : value(val), next(nullptr) {}
};

void insertAtHead(Node *&head, int val) {
  auto *newNode = new Node(val);
  newNode->next = head;
  head = newNode;
}

void insertAtEnd(Node *&head, int val) {
  auto *newNode = new Node(val);
  if (head == nullptr) {
    head = newNode;
    return;
  }

  auto *accessHead = head;

  while (accessHead and accessHead->next) {
    accessHead = accessHead->next;
  }
  accessHead->next = newNode;
}

// Append at index

void printList(const Node *head) {
  auto *accessHead = head;
  while (accessHead) {
    std::cout << accessHead->value << " -> ";
    accessHead = accessHead->next;
  }
  std::cout << "nullptr" << std::endl;
}

void freeList(Node *&head) {
  auto accessHead = head;
  while (accessHead) {
    auto newHead = accessHead->next;
    delete (accessHead);
    accessHead = newHead;
  }
  head = nullptr;
}

// int main() {
//   Node *head = new Node(10);
//   // Node *head = nullptr;
//   printList(head);
//   insertAtEnd(head, 20);
//   printList(head);
//   insertAtEnd(head, 30);
//   printList(head);
//   insertAtEnd(head, 40);
//   printList(head);
//   insertAtHead(head, 0);
//   printList(head);

//   std::cout << "Value at head: " << head->value << std::endl;
//   std::cout << "Next node addr: " << head->next << std::endl;

//   freeList(head);
// }

int main() {
  Node *head = nullptr;

  // ## Test Case 1: Operations on an empty list ##
  std::cout << "--- Testing on an Empty List ---" << std::endl;
  printList(head);  // Should print [empty]

  std::cout << "\nInserting 10 at the end..." << std::endl;
  insertAtEnd(head, 10);
  printList(head);  // List: 10 -> nullptr

  std::cout << "\nInserting 0 at the head..." << std::endl;
  insertAtHead(head, 0);
  printList(head);  // List: 0 -> 10 -> nullptr

  std::cout << "\nFreeing the list..." << std::endl;
  freeList(head);
  printList(head);  // Should print [empty]
  std::cout << "--------------------------------\n" << std::endl;

  // ## Test Case 2: Original sequence of operations ##
  std::cout << "--- Original Test Sequence ---" << std::endl;
  head = new Node(100);
  printList(head);
  insertAtEnd(head, 200);
  printList(head);
  insertAtEnd(head, 300);
  printList(head);
  insertAtHead(head, 50);
  printList(head);

  std::cout << "\nValue at head: " << head->value << std::endl;
  std::cout << "Next node address: " << head->next << std::endl;

  std::cout << "\nFreeing the list..." << std::endl;
  freeList(head);
  printList(head);
  std::cout << "----------------------------\n" << std::endl;

  // ## Test Case 3: Freeing a single-node list ##
  std::cout << "--- Testing a Single-Node List ---" << std::endl;
  head = new Node(999);
  printList(head);

  std::cout << "\nFreeing the list..." << std::endl;
  freeList(head);
  printList(head);
  std::cout << "----------------------------------\n" << std::endl;

  return 0;
}