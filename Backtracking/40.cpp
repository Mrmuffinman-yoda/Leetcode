#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> answer = {};
    vector<int> currSol = {};
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, target, 0, currSol, answer, 0);
    return answer;
  }

  void backtrack(vector<int> &candidates,
                 int target,
                 int index,
                 vector<int> &currSol,
                 vector<vector<int>> &answer,
                 int count) {
    if (count == target) {
      answer.push_back(currSol);
      return;
    } else if (count > target) {
      return;
    }

    for (int num = index; num < candidates.size(); num++) {
      if (num > index && candidates[num] == candidates[num - 1]) {
        continue;
      }

      int numToAdd = candidates[num];
      currSol.push_back(numToAdd);

      backtrack(candidates, target, num + 1, currSol, answer, count + numToAdd);
      currSol.pop_back();
    }
  }
};

int main() {
  vector<int> arr{10, 1, 2, 7, 6, 1, 5};
  int target = 8;

  Solution s;
  vector<vector<int>> ans = s.combinationSum2(arr, target);

  for (auto x : ans) {
    cout << "[";
    for (auto y : x) {
      cout << y << ", ";
    }
    cout << "]\n";
  }

  return 0;
}