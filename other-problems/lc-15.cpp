#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> sol;

    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int j = i + 1;
      int k = n - 1;

      while (j < k) {
        int s = nums[i] + nums[j] + nums[k];

        if (s == 0) {
          sol.push_back({nums[i], nums[j], nums[k]});
          j++;
          k--;

          while (j < k && nums[j] == nums[j - 1])
            j++;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        } else if (s < 0) {
          j++;
        } else {
          k--;
        }
      }
    }
    return sol;
  }
};
