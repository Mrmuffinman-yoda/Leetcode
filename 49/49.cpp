#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> wordSet = {};

    vector<vector<string>> result;
    for (string word : strs) {
      // sort the word
      string sortedword = word;
      sort(sortedword.begin(), sortedword.end());

      // now hash this into a dict
      if (wordSet.find(sortedword) != wordSet.end()) {
        wordSet[sortedword].push_back(word);
      } else {
        wordSet[sortedword] = {word};
      }
    }
    for (const auto& [_, group] : wordSet) {
      result.push_back(group);
    }

    return result;
  }
};

int main() {
  // Solution s = Solution();
  // vector<string> anagrams = {"eat", "tea", "tan", "ate", "nat", "bat"};
  // vector<vector<string>> answer = s.groupAnagrams(anagrams);

  return 0;
}