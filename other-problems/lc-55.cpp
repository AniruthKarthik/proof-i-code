#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int cangomax = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > cangomax)
        return false;
      cangomax = max(cangomax, i + nums[i]);
    }
    return true;
  }
};
