#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> finalAns{};
    vector<int> currAns{};

    sort(nums.begin(), nums.end());

    backtrack(nums, finalAns, currAns, 0);

    return finalAns;
  }

  void backtrack(vector<int>& nums,
                 vector<vector<int>>& finalAns,
                 vector<int>& currAns,
                 int index

  ) {
    finalAns.push_back(currAns);

    for (int i = index; i < nums.size(); i++) {
      if (i > index && nums[i] == nums[i - 1]) {
        continue;
      }
      currAns.push_back(nums[i]);

      backtrack(nums, finalAns, currAns, i + 1);

      currAns.pop_back();
    }
  }
};

int main() {
  Solution s;
  vector<int> input{1, 2, 2};
  vector<vector<int>> ans = s.subsetsWithDup(input);

  for (vector<int> x : ans) {
    cout << "[";
    for (int y : x) {
      cout << y << ", ";
    }
    cout << "]\n";
  }
  cout << "Code completed\n";

  return 0;
}