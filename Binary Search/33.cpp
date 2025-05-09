#include <cassert>
#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
      // check which side of the array is currently sorted

      int mid = lo + (hi - lo) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      // check if the left side is sorted
      if (nums[lo] < nums[mid]) {
        // now check if the number is between here
        if (nums[lo] <= target && target < nums[mid]) {
          // then we know the number is on the left half
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      } else {
        // check if the number is on the right hand side
        if (nums[mid] < target && target <= nums[hi]) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution s;
  vector<int> input = {
      4, 5, 6, 7, 0, 1, 2,
  };
  int answer = s.search(input, 0);
  assert(answer == 4);
  return 0;
}