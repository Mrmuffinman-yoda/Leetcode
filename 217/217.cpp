#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for (int val : nums) {
      if (seen.count(val)) return true;
      seen.insert(val);
    }

    return false;
  }
};

int main() {
  Solution s = Solution();
  vector<int> input = {3, 4, 5, 6, 1, 1, 88};
  bool ans = s.containsDuplicate(input);
  cout << ans;
  return 0;
}