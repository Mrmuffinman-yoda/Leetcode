#include <string>
#include <iostream>
#include <unordered_set>
#include <cmath>
#include <cassert>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
        {
            return 0;
        }
        int largestLen = 0;
        int counter = 0;
        unordered_set<int> seen;
        size_t left{0};
        for (size_t right{0}; right <= s.size() - 1; right++)
        {
            int8_t rightValue = s[right];

            while (seen.find(rightValue) != seen.end())
            {
                int8_t leftValue{s[left]};
                seen.erase(leftValue);
                counter--;
                left++;
            }

            counter++;
            largestLen = max(largestLen, counter);
            seen.insert(rightValue);
        }
        return largestLen;
    }
};
int main()
{
    Solution *s = new Solution();
    string text1 = "abcabcbb";
    string text2 = "bbbbb";
    string text3 = "pwwkew";
    string text4 = "";
    string text5 = "dvdf";

    assert(s->lengthOfLongestSubstring(text1) == 3);
    assert(s->lengthOfLongestSubstring(text2) == 1);
    assert(s->lengthOfLongestSubstring(text3) == 3);
    assert(s->lengthOfLongestSubstring(text4) == 0);
    assert(s->lengthOfLongestSubstring(text5) == 3);

    return 0;
}