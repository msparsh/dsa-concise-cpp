#include <iostream>
#include <vector>

// Fixed window size:
// 1. fix widow size k
// 2. take first window [0:k], and calculate result
// 3. for second window 'add' k+1th and 'subtract' 0th
// 4. so on until left == len

// Variable window size:
// left = right = 0
// 'add' right
//       if condition TRUE
//          'subtract' left until FALSE
// repeat until you reach the end and condition FALSE

int sum_i_to_j(std::vector<int> vec, int i, int j){
    // excluding jth value
    int r = 0;
    for (int c = i; c < j; c += 1){
        r += vec[c];
    }
    return r;
}

int fixed_sliding_window_sum(const std::vector<int> vec, int k){
    int last_sum = sum_i_to_j(vec, 0, k); // better to use stdlib fn
    int best_sum = last_sum;

    for (int i = 1; i <= vec.size() - k; i += 1){
        int new_sum = last_sum - vec[i - 1] + vec[i + k - 1];

        if (new_sum > best_sum){
            best_sum = new_sum;
        }
        last_sum = new_sum;
    }
    return best_sum;
}

int main(){
    std::vector<int> vec1 = {0, 2, 13, 4, 1, 6, 17, 1, 1, 9, 1};
    std::cout << "Max sum: " << fixed_sliding_window_sum(vec1, 5);
    return 0;
}
