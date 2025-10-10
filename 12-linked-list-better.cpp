#include <iostream>

// use std::forward_list instead of implementing

class Node {
 public:
  int value;
  Node *next;

  Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
  // uses shallow copy which can cause errors
 private:
  Node *head;

  void FreeList() {
    auto accessHead = head;
    while (accessHead) {
      auto newHead = accessHead->next;
      delete (accessHead);
      accessHead = newHead;
    }
    head = nullptr;
  }

 public:
  // constructor and destructor
  LinkedList() : head(nullptr) {}
  ~LinkedList() { FreeList(); }

  void InsertAtHead(int val) {
    auto *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
  }

  void InsertAtEnd(int val) {
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

  void DeleteNode(int val) {
    if (not head) {
      std::cout << "List is empty";
      return;
    }

    if (head->value == val) {
      auto to_delete = head;
      head = head->next;
      delete to_delete;
      return;
    }

    auto accessHead = head;
    auto trail = head;
    while (accessHead and accessHead->next) {
      accessHead = accessHead->next;
      if (accessHead->value == val) {
        trail->next = accessHead->next;
        delete accessHead;
        return;
      }
      trail = trail->next;
    }
    std::cout << "Did not find the value in list";
  }

  void PrintList() const {
    auto *accessHead = head;
    while (accessHead) {
      std::cout << accessHead->value << " -> ";
      accessHead = accessHead->next;
    }
    std::cout << "nullptr" << std::endl;
  }

  void ReverseList() {
    Node *prev = nullptr;
    Node *access = head;

    Node *temp = nullptr;

    while (access) {
      temp = access->next;
      access->next = prev;
      prev = access;
      access = temp;
    }

    head = prev;
  }

  void DetectCycle() const {
    auto turtle = head;  // slow pointer
    auto hare = head;    // fast pointer
    while (hare and hare->next) {
      turtle = turtle->next;
      hare = hare->next->next;
      if (turtle == hare) {
        std::cout << "Found cycle" << std::endl;
        return;
      }
    }
    std::cout << "Did not find cycle" << std::endl;
  }
};

int main() {
  LinkedList l1;
  l1.InsertAtEnd(10);
  l1.InsertAtEnd(20);
  l1.InsertAtEnd(30);
  l1.InsertAtEnd(40);
  l1.PrintList();
  l1.DeleteNode(30);
  l1.PrintList();
  return 0;
}