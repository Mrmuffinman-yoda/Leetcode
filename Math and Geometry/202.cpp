#include <cmath>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> seen = {};
    while (n != 1) {
      if (seen.find(n) != seen.end()) {
        return false;
      }
      int total = 0;
      seen.insert(n);

      while (n > 0) {
        total += pow(n % 10, 2);
        n /= 10;
      }
      n = total;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isHappy(19) << endl;  // should be true
}