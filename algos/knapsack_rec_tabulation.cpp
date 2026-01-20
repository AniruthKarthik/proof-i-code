#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int knapsack(int W, vector<int> &wt, vector<int> &val) {

    int n = wt.size();

    // dp[w] = max value with capacity w
    vector<int> dp(W + 1, 0);

    // loop over items
    for (int i = 0; i < n; i++) {

      // loop over capacity (BACKWARD)
      for (int w = W; w >= wt[i]; w--) {

        dp[w] = max(dp[w],                 // skip item
                    val[i] + dp[w - wt[i]] // take item
        );
      }
    }

    return dp[W];
  }
};

int main() {
  Solution s;

  vector<int> wt = {1, 3, 4, 5};
  vector<int> val = {1, 4, 5, 7};
  int W = 7;

  cout << "Maximum value: " << s.knapsack(W, wt, val) << endl;

  return 0;
}
