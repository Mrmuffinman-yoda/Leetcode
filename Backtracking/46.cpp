#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    vector<vector<int>> answer{};
    vector<int> currSol;
    backtrack(nums, used, answer, currSol);
    return answer;
  }

  void backtrack(vector<int>& nums,
                 vector<bool>& used,
                 vector<vector<int>>& ans,
                 vector<int>& currSol) {
    if (currSol.size() == nums.size()) {
      ans.push_back(currSol);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == false) {
        // add number
        currSol.push_back(nums[i]);
        used[i] = true;

        // recurse number
        backtrack(nums, used, ans, currSol);

        // remove number

        currSol.pop_back();
        used[i] = false;
      }
    }
  }
};

int main() {
  Solution s;
  vector<int> input{1, 2, 3};
  vector<vector<int>> ans = s.permute(input);

  for (auto x : ans) {
    cout << "[";
    for (auto y : x) {
      cout << y << ", ";
    }
    cout << "]\n";
  }

  return 0;
}