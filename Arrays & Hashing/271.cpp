// TODO: Not fully working

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
 public:
  string encode(vector<string>& strs) {
    string ans = "";

    for (auto word : strs) {
      ans = ans + '\x00' + to_string(word.length()) + word;
    }
    return ans;
  }

  vector<string> decode(string s) {
    int ptr = 0;

    vector<string> ans = {};
    while (ptr < s.size()) {
      // first look for #

      if (s[ptr] == '\x00') {
        ptr += 1;

        string size = "";
        // start counting digits
        while (isdigit(s[ptr])) {
          size += s[ptr];
          ptr += 1;
        }

        int i_size = stoi(size);

        string word = "";

        for (int i = 0; i < i_size; i++) {
          word += s[ptr];
          ptr++;
        }

        ans.push_back(word);
      }
    }
    return ans;
  }
};

int main() {
  vector<string> input = {"1,23", "45,6", "7,8,9"};
  Solution s;

  string encoded = s.encode(input);
  cout << encoded << endl;

  vector<string> decoded = s.decode(encoded);

  cout << "Answer: ";
  for (auto x : decoded) {
    cout << x << "\n";
  }
  return 0;
}
