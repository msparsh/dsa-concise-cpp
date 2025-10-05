#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> generate_all_substrings(const std::string& text) {
  const int len_text = text.length();
  std::vector<std::string> substrings;
  for (int i = 0; i < len_text; i++) {
    for (int j = 1; j <= len_text - i; j++) {
      substrings.push_back(text.substr(i, j));
    }
  }
  return substrings;
}

int main() {
  std::string text = "ABBBBBB";
  std::vector<std::string> substrings = generate_all_substrings(text);

  for (const std::string& sub_string : substrings) {
    std::cout << "Substring: " << sub_string << std::endl;
  }
}