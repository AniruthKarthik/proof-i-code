// time O(nxW)
// space O(W)

#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
  vector<int> dp(W + 1, 0);

  for (int i = 0; i < wt.size(); i++) {
    for (int w = W; w >= wt[i]; w--) {
      dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
    }
  }

  return dp[W];
}

int main() {
  vector<int> wt = {10, 20, 30};
  vector<int> val = {60, 100, 120};
  int W = 30;

  cout << knapsack(W, wt, val, wt.size());
}
