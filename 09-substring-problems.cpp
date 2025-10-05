#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> generate_all_substrings(const std::string& text) {
  // Use size_t instead of int for len or index
  const auto len_text = text.length();
  std::vector<std::string> substrings;

  for (size_t i = 0; i < len_text; i++) {
    for (size_t j = 1; j <= len_text - i; j++) {
      substrings.push_back(text.substr(i, j));
    }
  }
  return substrings;
}

std::string longest_common_substring(const std::string& str1,
                                     const std::string& str2) {
  // Common substring matrix
  std::vector<std::vector<int>> csm(str1.length() + 1,
                                    std::vector<int>(str2.length() + 1, 0));

  int best_length = 0;
  int right_index_in_text1 = 0;

  for (size_t i = 1; i <= str1.length(); i++) {
    for (size_t j = 1; j <= str2.length(); j++) {
      if (str1[i - 1] == str2[j - 1]) {
        csm[i][j] = csm[i - 1][j - 1] + 1;

        if (csm[i][j] > best_length) {
          best_length = csm[i][j];
          right_index_in_text1 = i;
        }
      } else {
        csm[i][j] = 0;
      }
    }
  }
  return str1.substr(right_index_in_text1 - best_length,
                     best_length);  // return "" if best_length is 0
}

int main() {
  const std::string text = "ABBBBBB";
  const auto substrings = generate_all_substrings(text);
  std::cout << "Substrings: ";
  for (const std::string& sub_string : substrings) {
    std::cout << sub_string << " ";
  }
  std::cout << std::endl;

  std::string text1 = "jhsfijbABCajvbfaZZZsjvb";
  std::string text2 = "ijZZZsdfsABCDbvbfvijfn";
  auto lcs = longest_common_substring(text1, text2);
  std::cout << "LCS: " << lcs << std::endl;

  return 0;
}