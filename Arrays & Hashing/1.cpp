#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // 1. loop through once
    // 2. calculate difference with target
    // 3. save difference:index in map
    // 4. check next value if its in dict, if so return index pair, else add
    // again to map

    unordered_map<int, int> indicies = {};

    for (int i = 0; i < nums.size(); i++) {
      int number = nums[i];
      if (indicies.find(number) == indicies.end()) {
        int difference = target - number;
        indicies[difference] = i;
      } else {
        // it is in map, return value
        return vector<int>{indicies[number], i};
      }
    }
    return vector<int>{-1};
  }
};

int main() {
  Solution s = Solution();
  vector<int> input = {2, 7, 11, 15};
  vector<int> result = s.twoSum(input, 9);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}