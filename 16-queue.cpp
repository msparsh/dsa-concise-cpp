#include <iostream>
#include <stdexcept>

class Node {
 public:
  int val;
  Node* next;
  Node(int value) : val(value), next(nullptr) {}
};

class Queue {
 private:
  Node* head;
  Node* rear;
  size_t qsize;

 public:
  Queue() : head(nullptr), rear(nullptr), qsize(0) {}
  ~Queue() {
    while (head != nullptr) {
      auto temp = head;
      head = head->next;
      delete temp;
    }
  }

  void enqueue(int value) {
    auto newNode = new Node(value);
    if (empty()) {
      head = newNode;
      rear = newNode;
    } else {
      rear->next = newNode;
      rear = rear->next;
    }

    qsize++;
  }

  void dequeue() {
    if (empty()) {
      return;

    } else {
      auto temp = head;
      head = head->next;
      if (empty()) {
        rear = nullptr;
      }
      delete temp;
      qsize--;
    }
  }

  bool empty() const {
    // return true if q empty
    return head == nullptr;
  }

  int front() const {
    if (not empty()) {
      return head->val;
    }
    throw std::runtime_error("Queue is empty");
  }

  int size() const {
    //
    return qsize;
  }
};

int main() {
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  std::cout << "Current queue size: " << q.size() << std::endl;
  std::cout << "Front element is: " << q.front() << std::endl;

  std::cout << "Dequeuing..." << std::endl;
  q.dequeue();

  std::cout << "New front element is: " << q.front() << std::endl;
  std::cout << "Queue size is now: " << q.size() << std::endl;

  return 0;
}