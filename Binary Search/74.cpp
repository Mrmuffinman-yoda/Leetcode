#include <iostream>
#include <vector>

using namespace std;

// TODO : redo this question
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // look through the
    int rows = matrix.size();
    int columns = matrix[0].size();

    int lo = 0;
    int hi = (rows * columns) - 1;

    while (lo <= hi) {
      int mid = (lo + hi) / 2;

      int midValue = matrix[mid / columns][mid % columns];

      if (midValue == target) {
        return true;
      } else if (midValue < target) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return false;
  }
};

int main() {
  Solution s;

  vector<vector<int>> inputMatrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  bool ans = s.searchMatrix(inputMatrix, 20);

  return ans;
}