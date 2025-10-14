#include <algorithm>
#include <iostream>
#include <stack>

class MinStack {
 private:
  // val, min_val
  std::stack<std::pair<int, int>> min_stack;

 public:
  MinStack() {}

  bool empty() { return min_stack.empty(); }

  void push(int val) {
    if (min_stack.empty()) {
      min_stack.push({val, val});
    } else {
      min_stack.push({val, std::min(val, min_stack.top().second)});
    }
  }

  void pop() {
    if (not min_stack.empty()) {
      min_stack.pop();
    }
  }

  int top() {
    if (not min_stack.empty()) {
      return min_stack.top().first;
    }
    throw std::runtime_error("Empty stack");
  }

  int get_min() {
    if (not min_stack.empty()) {
      return min_stack.top().second;
    }
    throw std::runtime_error("Empty stack");
  }
};

int main() {
  MinStack stack;

  stack.push(5);
  stack.push(2);
  stack.push(8);

  std::cout << stack.get_min() << std::endl;

  stack.pop();
  stack.pop();

  std::cout << stack.get_min() << std::endl;
  return 0;
}