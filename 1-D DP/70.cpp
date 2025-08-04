#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  unordered_map<int, int> memo;
  int recurse(int n, size_t currentCount) {
    // base case, if currentCount == n return 1, if its bigger then return 0

    if (currentCount == n) {
      return 1;
    } else if (currentCount > n) {
      return 0;
    }
    if (memo.find(currentCount) != memo.end()) {
      return memo[currentCount];
    }

    memo[currentCount] =
        recurse(n, currentCount + 1) + recurse(n, currentCount + 2);
    return memo[currentCount];
  }

  int climbStairs(int n) {
    memo.clear();
    return recurse(n, 0);
  }
};

int main() {
  Solution s;

  cout << "answer: " << s.climbStairs(2) << "\n";
  cout << "answer: " << s.climbStairs(3) << "\n";
  cout << "answer: " << s.climbStairs(44) << "\n";

  return 0;
}