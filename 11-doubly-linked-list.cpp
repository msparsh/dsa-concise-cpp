#include <iostream>

// Use std::list instead of implementing

// Node:
//     val
//     next ptr
//     prev ptr

// 1. this allows backward traversal as well.
// 2. so much better
// 3. more memory
// 4. ops: insert, del, fwd, bwd, print
// 5. example: nullptr <-> first <-> second <-> nullptr

class Node {
 public:
  int value;
  Node* next;
  Node* prev;

  Node(int val) : value(val), next(nullptr), prev(nullptr) {
    // For any additional things to do after obj creation
    // Or for Constructor body assignment like:
    //  value = val;
  }
};

class DoublyLinkedList {
 private:
  Node* head;
  Node* tail;

 public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  void print() {
    auto accessHead = head;
    while (accessHead) {
      std::cout << accessHead->value << " <-> ";
      accessHead = accessHead->next;
    }
    std::cout << "nullptr" << std::endl;
  }

  void InsertAtStart(int val) {
    auto newNode = new Node(val);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  void InsertAtEnd(int val) {
    auto newNode = new Node(val);
    if (tail == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }

  ~DoublyLinkedList() {
    Node* accessHead = head;
    while (accessHead != nullptr) {
      Node* nodeToDelete = accessHead;
      accessHead = accessHead->next;
      delete nodeToDelete;
    }
  }
};

int main() {
  DoublyLinkedList l1;

  l1.InsertAtEnd(5);
  l1.InsertAtEnd(10);
  l1.InsertAtEnd(15);
  l1.InsertAtStart(0);
  l1.InsertAtEnd(20);
  l1.print();

  return 0;
}