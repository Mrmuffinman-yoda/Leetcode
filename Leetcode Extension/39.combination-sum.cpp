#include <vector>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> answer{};
    int t;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        t = target;
        backtrack(candidates, 0, {}, 0);
        return answer;
    }
    void backtrack(vector<int> &candidates, size_t index, vector<int> currentAns, int currentSum)
    {
        if (currentSum > t || index > candidates.size())
        {
            return;
        }
        else if (currentSum == t)
        {
            answer.push_back(currentAns);
            return;
        }

        for (int val : candidates)
        {
            // don't add the value
            backtrack(candidates, index + 1, currentAns, currentSum);

            // add the value
            currentAns.push_back(val);
            backtrack(candidates, index + 1, currentAns, currentSum + val);
        }
    }
};
// @lc code=end

int main()
{
    vector<int> input = {2, 3, 6, 7};
    int target = 7;
    Solution s;
    vector<vector<int>> ans = s.combinationSum(input, target);

    for (vector<int> arr : ans)
    {
        cout << "[";
        for (int val : arr)
        {
            cout << val << ",";
        }
        cout << "]" << "\n";
    }
    return 0;
}
