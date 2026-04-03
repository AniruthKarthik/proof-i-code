#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int ma = 0;
    int i = 0, j = height.size() - 1;

    while (i < j) {
      int ar = (j - i) * min(height[i], height[j]);
      ma = max(ma, ar);

      if (height[i] < height[j]) {
        i++;
      } else {
        j--;
      }
    }
    return ma;
  }
};
