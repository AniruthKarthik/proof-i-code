#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0)
      return 0;
    int buy = prices[0];
    int prof = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < buy) {
        buy = prices[i];
      }
      prof = max(prof, prices[i] - buy);
    }
    return prof;
  }
};
