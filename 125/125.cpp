#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  inline char toLower(char c) { return ('A' <= c <= 'Z') ? c + 32 : c; }
  bool isPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;

    while (l < r) {
      while (l < r && !isalnum(s[l])) {
        l++;
      }
      while (l < r && !isalnum(s[r])) {
        r--;
      }

      if (tolower(s[l]) != tolower(s[r])) {
        return false;
      }
      l++;
      r--;
    }

    return true;
  }
};

int main() {
  string c = ".,";

  Solution s = Solution();
  cout << s.isPalindrome(c);
}