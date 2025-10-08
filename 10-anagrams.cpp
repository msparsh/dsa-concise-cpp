#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

bool IsAnagramWithSorting(const std::string s1, const std::string s2) {
  if (s1.length() != s2.length()) {
    return false;
  }

  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());

  return s1 == s2;
}

std::unordered_map<char, int> GetFreqCountMap(const std::string& s) {
  std::unordered_map<char, int> map;
  for (char c : s) {
    map[c]++;
  }
  return map;
}

bool IsAnagramFreqCount(const std::string& s1, const std::string& s2) {
  if (s1.length() != s2.length()) {
    return false;
  }

  return GetFreqCountMap(s2) == GetFreqCountMap(s1);
}

bool IsAnagramFreqCountFast(const std::string& s1, const std::string& s2) {
  if (s1.length() != s2.length()) {
    return false;
  }
  auto freq_map = GetFreqCountMap(s1);

  for (char c : s2) {
    if (freq_map[c] <= 0) {
      return false;
    }
    freq_map[c]--;
  }
  return true;
}

int main() {
  std::string s1 = "aab";
  std::string s2 = "aaa";

  if (IsAnagramWithSorting(s1, s2)) {
    std::cout << "Are anagrams" << std::endl;
  } else {
    std::cout << "Not anagrams" << std::endl;
  }

  if (IsAnagramFreqCount(s1, s2)) {
    std::cout << "Are anagrams with freq counting" << std::endl;
  } else {
    std::cout << "Not anagrams with freq counting" << std::endl;
  }

  if (IsAnagramFreqCountFast(s1, s2)) {
    std::cout << "Are anagrams with freq counting single map" << std::endl;
  } else {
    std::cout << "Not anagrams with freq counting single map" << std::endl;
  }
}
