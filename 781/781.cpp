#include <cassert>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int numRabbits(std::vector<int>& answers) {
    int minimum = 0;

    std::unordered_map<int, int> seenValues = {};
    for (int value : answers) {
      if (value == 0) {
        minimum += 1;
      } else {
        seenValues[value]++;
      }
    }

    for (const auto& pair : seenValues) {
      int minimumGroupCount = (pair.second + pair.first) / (pair.first + 1);
      minimum += minimumGroupCount * (pair.first + 1);
    }

    std::cout << minimum;
    return minimum;
  }
};

int main() {
  Solution x = Solution();
  std::vector<int> input = {1, 1, 2};
  assert(x.numRabbits(input) == 5);

  std::vector<int> input2 = {10, 10, 10};
  assert(x.numRabbits(input2) == 11);

  std::vector<int> input3 = {2, 2, 2, 2, 2, 2};
  assert(x.numRabbits(input3) == 6);
}
