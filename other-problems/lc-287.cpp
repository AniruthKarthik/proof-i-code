#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    unordered_map<int, bool> exists;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (exists.find(nums[i]) != exists.end()) {
        return nums[i];
      } else {
        exists[nums[i]] = true;
      }
    }

    return -1;
  }
};
