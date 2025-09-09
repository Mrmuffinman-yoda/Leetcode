#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    // calculate total multiplication

    vector<int> answer = {1};

    for (int i = 1; i < nums.size(); i++) {
      int previousNumber = answer[i - 1];
      int numb = nums[i - 1];
      answer.push_back(previousNumber * numb);
    }

    int right_product = 1;

    for (int i = nums.size() - 1; i >= 0; i--) {
      answer[i] *= right_product;
      right_product *= nums[i];
    }
    return answer;
  }
};

int main() {
  Solution s;
  vector<int> input{1, 2, 3, 4};

  vector<int> ans = s.productExceptSelf(input);

  for (auto x : ans) {
    cout << x << ", ";
  }

  return 0;
}