#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> answer = {};
    backtrack(candidates, target, 0, {}, answer);
    return answer;
  }

  void backtrack(vector<int> &candidates,
                 int target,
                 int index,
                 vector<int> currSol,
                 vector<vector<int>> &answer) {
    int sum = 0;
    for (auto x : currSol) sum += x;
    if (sum == target) {
      answer.push_back(currSol);
      return;
    } else if (sum > target) {
      return;
    }

    for (int num = index; num < candidates.size(); num++) {
      currSol.push_back(candidates[num]);

      backtrack(candidates, target, num, currSol, answer);

      currSol.pop_back();
    }
  }
};

int main() {
  vector<int> arr{2, 3, 6, 7};
  int target = 7;

  Solution s;
  vector<vector<int>> ans = s.combinationSum(arr, target);

  for (auto x : ans) {
    for (auto y : x) {
      cout << y << "\n";
    }
    cout << "\t";
  }

  return 0;
}