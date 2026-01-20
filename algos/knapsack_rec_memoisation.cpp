#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int dp[1001][1001];

  // Recursive function with memoization
  int knapsack(int i, int W, vector<int> &wt, vector<int> &val) {
    if (i < 0 || W == 0)
      return 0;

    if (dp[i][W] != -1)
      return dp[i][W];

    // If item is too heavy, skip
    if (wt[i] > W)
      return dp[i][W] = knapsack(i - 1, W, wt, val);

    // Take or skip
    int take = val[i] + knapsack(i - 1, W - wt[i], wt, val);
    int skip = knapsack(i - 1, W, wt, val);

    return dp[i][W] = max(take, skip);
  }
};

int main() {
  Solution s;

  vector<int> wt = {1, 3, 4, 5};
  vector<int> val = {1, 4, 5, 7};
  int W = 7;
  int n = wt.size();

  // Initialize dp with -1
  memset(s.dp, -1, sizeof(s.dp));

  cout << "Maximum value: " << s.knapsack(n - 1, W, wt, val) << endl;

  return 0;
}
