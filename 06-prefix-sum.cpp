#include <iostream>
#include <vector>

// Prefix sum
// basically cumulative density fn
// Algorithm:
//      find sums from start and make a list
//      that is [0->0, 0->1, 0->2, ..., 0->last] list of sums
//      now to find sum i->j = (i->j) - (0->i-1) including ith and jth elements

std::vector<int> prefixSum(const std::vector<int>& list) {
  std::vector<int> pS;
  int sum = 0;
  for (int i = 0; i < list.size(); i++) {
    sum += list[i];
    pS.push_back(sum);
  }
  return pS;
}

int main() {
  std::vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> pS = prefixSum(list);

  std::cout << "Prefix Sum Array: ";
  for (int sum : pS) {
    std::cout << sum << " ";
  }
  std::cout << std::endl;
}