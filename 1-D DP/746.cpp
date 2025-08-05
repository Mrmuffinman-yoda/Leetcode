#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    for (int i = cost.size() - 3; i >= 0; i--) {
      cost[i] = min(cost[i] + cost[i + 1], cost[i] + cost[i + 2]);
    }
    return min(cost[0], cost[1]);
  }
};

int main() {
  Solution s;
  vector<int> input{10, 15, 20};

  int ans = s.minCostClimbingStairs(input);
  cout << "Answer : " << ans << "\n";

  vector<int> input2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

  int ans2 = s.minCostClimbingStairs(input2);
  cout << "Answer : " << ans2 << "\n";
  return 0;
}