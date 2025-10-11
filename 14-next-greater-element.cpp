#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> NGE(const std::vector<int> vec) {
  if (vec.empty()) {
    return vec;
  }

  std::stack<int> st;
  std::vector<int> nge;

  for (int i = vec.size() - 1; i >= 0; i--) {
    while (not st.empty() and st.top() <= vec[i]) {
      st.pop();
    }

    if (st.empty()) {
      nge.push_back(-1);
    } else {
      nge.push_back(st.top());
    }
    st.push(vec[i]);
  }

  std::reverse(nge.begin(), nge.end());
  return nge;
}

std::vector<int> NaiveNGE(const std::vector<int> vec) {
  if (vec.empty()) {
    return vec;
  }

  std::vector<int> nge_vector;
  bool found = false;

  for (int i = 0; i < vec.size(); i++) {
    for (int j = i + 1; j < vec.size(); j++) {
      if (vec[i] < vec[j]) {
        nge_vector.push_back(vec[j]);
        found = true;
        break;
      }
    }
    if (not found) {
      nge_vector.push_back(-1);
    }
    found = false;
  }
  return nge_vector;
}

int main() {
  std::vector<int> vec = {4, 5, 2, 10};

  auto nge = NaiveNGE(vec);
  for (int i : nge) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  auto nge2 = NGE(vec);
  for (int i : nge2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}