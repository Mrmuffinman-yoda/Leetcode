#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int rob_next_plus_one = 0;
    int rob_next = 0;

    for (int i = nums.size() - 1; i >= 0; i--) {
      int current = max(rob_next, nums[i] + rob_next_plus_one);

      rob_next_plus_one = rob_next;
      rob_next = current;
    }
    return rob_next;
  }
};

int main() {
  vector<int> input{1, 2, 3, 1};
  Solution s;
  int ans = s.rob(input);

  cout << "Answer : " << ans << "\n";
}
