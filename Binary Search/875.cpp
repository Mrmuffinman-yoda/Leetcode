#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int hi = *max_element(piles.begin(), piles.end());
    int lo = 1;

    int minVal = hi;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      if (isValid(mid, h, piles)) {
        minVal = min(mid, minVal);
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return minVal;
  }

  bool isValid(int val, int h, vector<int>& arr) {
    for (int pile : arr) {
      int remainder =
          (pile + val - 1) / val;  // TODO , learn why this line works
      h -= remainder;
    }
    if (h < 0) {
      return false;
    } else {
      return true;
    }
  }
};

int main() {
  Solution s;
  vector<int> input = {1000000000};
  int ans = s.minEatingSpeed(input, 2);
  cout << ans;
  return 0;
}