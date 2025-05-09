#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // initiate the window

    int lo = prices[0];
    int hi = 0;
    int cMax = 0;

    for (int dayprice : prices) {
      if (dayprice < lo) {
        cMax = max(cMax, hi - lo);
        lo = dayprice;
        hi = 0;
      } else {
        if (dayprice > hi) {
          hi = dayprice;
        }
      }
    }
    cMax = max(cMax, hi - lo);
    return cMax;
  }
};

int main() {
  Solution s;
  vector<int> input = {7, 1, 5, 3, 6, 4};
  int answer = s.maxProfit(input);
  assert(answer == 5);

  return 0;
}