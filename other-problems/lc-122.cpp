#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n == 0)
      return 0;
    int buy = prices[0];
    int prof = 0;
    for (int i = 1; i < n; i++) {
      if (prices[i] < prices[i - 1]) {
        prof += (prices[i - 1] - buy);
        buy = prices[i];
      }
      if (prices[i] < buy)
        buy = prices[i];
    }
    prof += (prices[n - 1] - buy);

    return prof;
  }
};
