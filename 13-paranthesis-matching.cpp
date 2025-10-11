#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

bool ParanthesisMatching(std::string s) {
  std::unordered_map<char, char> map = {
      {']', '['}, {'>', '<'}, {')', '('}, {'}', '{'}};
  std::stack<char> st;

  for (const char c : s) {
    if (c == '<' or c == '(' or c == '[' or c == '{') {
      st.push(c);
    } else if (c == '>' or c == ')' or c == ']' or c == '}') {
      if (st.empty() or st.top() != map[c]) {
        return false;
      } else {
        st.pop();
      }
    }
  }

  return st.empty();
}

int main() {
  std::string s1 = "{<()[]>}";  // matches
  std::string s2 = "([)]";      // does  not match

  if (ParanthesisMatching(s1)) {
    std::cout << "Result: Matching! " << std::endl;
  } else {
    std::cout << "Result: Not Matching. " << std::endl;
  }

  if (ParanthesisMatching(s2)) {
    std::cout << "Result: Matching! " << std::endl;
  } else {
    std::cout << "Result: Not Matching. " << std::endl;
  }

  return 0;
}