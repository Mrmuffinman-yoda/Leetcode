#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    vector<char> stack;

    unordered_map<char, char> bracket_map{{']', '['}, {'}', '{'}, {')', '('}};

    for (auto bracket : s) {
      if (bracket_map.find(bracket) != bracket_map.end()) {
        if (!stack.empty() && (stack.back() == bracket_map[bracket])) {
          stack.pop_back();
        } else {
          return false;
        }
      } else {
        stack.push_back(bracket);
      }
    }
    if (stack.empty()) {
      return true;
    }
    return false;
  }
};

int main() {
  string input = "]";
  Solution s;

  bool answer = s.isValid(input);

  cout << "Answer: " << answer << "\n";
  return 0;
}