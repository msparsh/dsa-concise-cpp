#include <iostream>
#include <unordered_map>
#include <vector>

// Frequency maps
// that is Count fn
// use unordered map for storing, like a dict

std::unordered_map<int, int> frequencyMap(const std::vector<int>& list) {
  std::unordered_map<int, int> fMap;
  for (int i = 0; i < list.size(); i++) {
    fMap[list[i]]++;

    // No need to check if el in map but wrote anyway
    // if (fMap.count(list[i]) == 0){
    //     fMap[list[i]] = 1;
    // }
    // else{
    //     fMap[list[i]]+=1;
    // }
  }
  return fMap;
}

int main() {
  std::vector<int> list = {1, 1, 1, 2, 2, 3, 3, 3, 3,
                           4, 5, 6, 7, 7, 8, 9, 9, 9};
  std::unordered_map<int, int> fMap = frequencyMap(list);

  for (const auto& pair : fMap) {
    std::cout << "Number: " << pair.first << ", Frequency: " << pair.second
              << std::endl;
  }
}