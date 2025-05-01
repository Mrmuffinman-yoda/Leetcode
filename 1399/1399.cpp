#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int countLargestGroup(int n) {
    if (n < 10) {
      return n;
    }

    int tally[37] = {};
    int highestVal = 0;
    int countHighest = 0;

    for (int currVal = 1; currVal <= n; currVal++) {
      int digitCount = 0;
      int i = currVal;

      while (i > 0) {
        digitCount += i % 10;
        i /= 10;
      }
      tally[digitCount]++;
    }

    for (int i = 0; i < 37; i++) {
      if (tally[i] == highestVal) {
        countHighest++;
      } else if (tally[i] > highestVal) {
        highestVal = tally[i];
        countHighest = 1;
      }
    }
    return countHighest;
  }
};

int main() {
  Solution solution = Solution();
  cout << solution.countLargestGroup(125) << " \n";
  return 0;
}