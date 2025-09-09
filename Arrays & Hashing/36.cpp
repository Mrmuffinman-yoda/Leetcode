#include <iostream>
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> columns(9);
    map<pair<int, int>, unordered_set<char>> boxes;

    for (int row = 0; row < 9; row++) {
      for (int column = 0; column < 9; column++) {
        char number = board[row][column];

        if (number == '.') {
          continue;
        }

        pair<int, int> coords = {row / 3, column / 3};

        if (rows[row].count(number) || columns[column].count(number) ||
            boxes[coords].count(number)) {
          return false;
        }

        rows[row].insert(number);
        columns[column].insert(number);
        boxes[coords].insert(number);
      }
    }

    return true;
  }
};

int main() {
  std::vector<std::vector<char>> validBoard = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'5', '6', '.', '.', '.', '.', '2', '8',
       '.'},  // '5' here duplicates the one in row 0, column 0
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  Solution s;

  cout << s.isValidSudoku(validBoard);
  return 0;
}
