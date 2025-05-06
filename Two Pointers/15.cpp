#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> answerset = {};

    for (int i = 0; i < nums.size(); i++) {
      // take the first value and match it with another two to get the final
      // value

      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int lo = i + 1;
      int hi = nums.size() - 1;

      while (lo < hi) {
        int tally = nums[i] + nums[lo] + nums[hi];
        if (tally == 0) {
          answerset.push_back({nums[i], nums[lo], nums[hi]});

          while (lo < hi && nums[lo] == nums[lo + 1]) lo++;

          while (lo < hi && nums[hi] == nums[hi - 1]) hi--;

          lo++;
        } else if (tally > 0) {
          hi--;
        } else {
          lo++;
        }
      }
    }
    return answerset;
  }
};

int main() {
  Solution s;
  vector<int> input = {0, 0, 0};
  vector<vector<int>> answer = s.threeSum(input);

  for (auto& arr : answer) {
    for (int num : arr) {
      cout << num << "\t";
    }
    cout << "\n";
  }
}