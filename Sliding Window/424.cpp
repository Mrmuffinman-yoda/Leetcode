#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int mostRepeatedChar(unordered_map<char, int> seen)
    {
        int mostRepeatedChar{0};
        for (auto [_, j] : seen)
        {
            mostRepeatedChar = max(mostRepeatedChar, j);
        }
        return mostRepeatedChar;
    }

    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> seen{};
        int result{0};
        size_t left{0};

        for (size_t right{0}; right <= s.size() - 1; right++)
        {
            char16_t rightChar = s[right];
            // add the character to map
            seen[rightChar]++;

            while ((right - left + 1) - mostRepeatedChar(seen) > k)
            {
                char16_t leftChar = s[left];

                seen[leftChar]--;
                left++;
            }
            result = max(result, static_cast<int>(right - left + 1));
        }

        return result;
    }
};

int main()
{
    Solution *s = new Solution();

    assert(s->characterReplacement("ABAB", 2) == 4);
    assert(s->characterReplacement("AABABBA", 1) == 4);
    assert(s->characterReplacement("AAAA", 2) == 4);

    return 0;
}