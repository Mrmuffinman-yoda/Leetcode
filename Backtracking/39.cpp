#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> answer = {};
    vector<int> currSol = {};
    backtrack(candidates, target, 0, currSol, answer, 0);
    return answer;
  }

  void backtrack(vector<int> &candidates,
                 int target,
                 int index,
                 vector<int> &currSol,
                 vector<vector<int>> &answer,
                 int count) {
    int sum = 0;
    if (count == target) {
      answer.push_back(currSol);
      return;
    } else if (count > target) {
      return;
    }

    for (int num = index; num < candidates.size(); num++) {
      int numToAdd = candidates[num];
      currSol.push_back(numToAdd);

      backtrack(candidates, target, num, currSol, answer, count + numToAdd);

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