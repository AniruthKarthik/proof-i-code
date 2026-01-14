#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;
// class Solution {
// public:
//     int sol(int i, int sum, int target, vector<int>& nums, int n) {
//         if (i == nums.size())
//             return sum == target;
//         int plus = sol(i + 1, (sum + nums[i]), target, nums, n);
//         int sub = sol(i + 1, (sum - nums[i]), target, nums, n);
//         return plus + sub;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int ans = sol(0, 0, target, nums, nums.size());
//         return ans;
//     }
// };
class Solution {
public:
  unordered_map<long long, int> dp;
  int sol(int i, int sum, int target, vector<int> &nums) {
    if (i == nums.size())
      return sum == target;
    long long key = ((long long)i << 32) | (sum + 20000);
    if (dp.count(key))
      return dp[key];

    return dp[key] = sol(i + 1, sum + nums[i], target, nums) +
                     sol(i + 1, sum - nums[i], target, nums);
  }
  int findTargetSumWays(vector<int> &nums, int target) {
    return sol(0, 0, target, nums);
  }
};
int main() {
  Solution sol;
  vector<int> nums = {1, 1, 1, 1, 1};
  int target = 3;
  cout << sol.findTargetSumWays(nums, target);
}
