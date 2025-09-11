#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    size_t left = 0;

    size_t right = height.size() - 1;

    int max_area = 0;

    while (left < right) {
      int area = min(height[left], height[right]) * (right - left);
      max_area = max(max_area, area);

      if (height[left] > height[right]) {
        right--;
      } else {
        left++;
      }
    }
    return max_area;
  }
};

int main() {
  Solution s;
  vector<int> input{1, 8, 6, 2, 5, 4, 8, 3, 7};
  int output = s.maxArea(input);

  cout << output << "\n";

  return 0;
}