#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> values(nums.begin(), nums.end());
    int highestcount = 0;
    for (int currVal : values) {
      if (values.find(currVal - 1) == values.end()) {
        int count = 1;
        while (values.find(currVal + 1) != values.end()) {
          count++;
          currVal++;
        }
        highestcount = max(highestcount, count);
      }
    }
    return highestcount;
  }
};

int main() {
  Solution s;
  vector<int> input = {300, 1, 200, 2, 4, 3};
  int ans = s.longestConsecutive(input);
  cout << ans;
  return 0;
}