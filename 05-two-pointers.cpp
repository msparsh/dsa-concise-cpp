#include <iostream>
#include <vector>

// Two patterns:
// 1. Opposite end pointers:
//          in sorted list, find two elements with target sum
//          left = 0,  right =-1
//          if sum > target:
//                  move right-- reduce sum
//          if sum < target:
//                  move left++ to increase sum
//          until target or left > right
// 2. Fast-Slow pointer --> cycle detection in linked lists (later)

void twoSum(const std::vector<int>& list, const int target) {
  // Take a sorted list, return two elements that sum up to the target
  int left = 0;
  int right = list.size() - 1;

  while (left < right) {
    if (list[left] + list[right] == target) {
      std::cout << list[left] << " " << list[right] << std::endl;
      return;
    } else if (list[left] + list[right] < target) {
      left++;
    } else if (list[left] + list[right] > target) {
      right--;
    }
  }
}

int main() {
  std::vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target = 15;
  twoSum(list, target);
}
