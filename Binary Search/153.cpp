#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo < hi) {
      int mid = (hi + lo) / 2;
      if (nums[mid] > nums[hi]) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return nums[lo];
  }
};

int main() {
  Solution s;

  vector<int> input1 = {3, 1, 2};
  assert(s.findMin(input1) == 1);  // Test case 1

  vector<int> input2 = {2, 1};
  assert(s.findMin(input2) == 1);  // Test case 2

  vector<int> input3 = {3, 4, 5, 1, 2};
  assert(s.findMin(input3) == 1);  // Test case 3

  vector<int> input4 = {4, 5, 6, 7, 0, 1, 2};
  assert(s.findMin(input4) == 0);  // Test case 4

  vector<int> input5 = {11, 13, 15, 17};
  assert(s.findMin(input5) == 11);  // Test case 5
  return 0;
}