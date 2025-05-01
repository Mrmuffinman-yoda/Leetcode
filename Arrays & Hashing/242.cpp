#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    // hash S
    unordered_map<char, int> s_hash = {};
    unordered_map<char, int> t_hash = {};
    for (char c : s) {
      s_hash[c]++;
    }

    for (char c : t) {
      t_hash[c]++;
    }

    return t_hash == s_hash;
  }

  bool isAnagram2(string s, string t) {
    int letters[28] = {};

    for (char c : s) {
      letters[int(c) - 97]++;
    }

    for (char c : t) {
      letters[int(c) - 97]++;
      letters[int(c) - 97]++;
    }

    for (int value : letters) {
      if (value % 3 != 0) {
        return false;
      }
    }
    return true;
  }

  bool isAnagram3(string s, string t) {
    int letters[28] = {};

    for (char cr : s) {
      letters[int(cr) - 97]++;
    }

    for (char cr : t) {
      letters[int(cr) - 97]--;
    }

    for (int count : letters) {
      if (count != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s = Solution();
  bool ans = s.isAnagram2("rat", "tar");
  cout << ans << "\n";
  return 0;
}