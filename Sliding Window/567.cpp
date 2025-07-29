#include <array>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
        {
            return false;
        }

        array<char, 26> seen1{};
        array<char, 26> seen2{};

        for (char c : s1)
            seen1[c - 'a']++;

        for (size_t i = 0; i < s1.size(); i++)
            seen2[s2[i] - 'a']++;

        if (seen1 == seen2)
            return true;

        size_t left = 0;

        for (size_t right = s1.size(); right < s2.size(); right++)
        {

            seen2[s2[right] - 'a']++;
            seen2[s2[right - s1.size()] - 'a']--;

            if (seen1 == seen2)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    Solution s;
    cout << "result: " << s.checkInclusion("ab", "eidbaooo") << "\n";
    return 0;
}