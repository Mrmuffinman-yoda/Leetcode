#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <array>
using namespace std;

class Solution
{
public:
    int mostRepeatedChar(array<int, 26> &seen)
    {
        int mostRepeatedChar{0};
        for (auto x : seen)
        {
            mostRepeatedChar = max(mostRepeatedChar, x);
        }
        return mostRepeatedChar;
    }

    int characterReplacement(string s, int k)
    {
        array<int, 26> seen{};
        int result{0};
        size_t left{0};

        for (size_t right{0}; right <= s.size() - 1; right++)
        {
            int rightChar = s[right];
            // add the character to map
            seen[rightChar - 65]++;

            while ((right - left + 1) - mostRepeatedChar(seen) > k)
            {
                int leftChar = s[left];

                seen[leftChar - 65]--;
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