#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> answer = {};
  vector<vector<int>> subsets(vector<int>& nums) {
    dfs({}, nums, 0);
    return answer;
  }

  void dfs(vector<int> currentAns, vector<int>& input, int currentVal) {
    // don't add currentVal

    if (currentVal == input.size()) {
      answer.push_back(currentAns);
      return;
    }

    dfs(currentAns, input, currentVal + 1);

    currentAns.push_back(input[currentVal]);

    dfs(currentAns, input, currentVal + 1);
  }
};