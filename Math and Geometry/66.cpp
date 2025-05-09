#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    bool remainder = false;
    digits[digits.size() - 1] += 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (remainder) {
        digits[i] += 1;
        remainder = false;
      }
      if (digits[i] >= 10) {
        digits[i] = digits[i] % 10;
        remainder = true;
      }
    }
    if (remainder) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};

int main() {
  Solution s;
  vector<int> input = {9, 9, 9};
  vector<int> ans = s.plusOne(input);
  for (int i : ans) {
    cout << i << endl;
  }
}