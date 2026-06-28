#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int heldKarp(vector<vector<int>> &dist) {
  int n = dist.size();

  int totMasks = 1 << n;

  vector<vector<int>> dp(totMasks, vector<int>(n, INT_MAX));

  //| Mask | City 0 | City 1 | City 2 | City 3 |
  //| ---- | -----: | -----: | -----: | -----: |
  //| 0000 |    INF |    INF |    INF |    INF |
  //| 0001 |    INF |    INF |    INF |    INF |
  //| 0010 |    INF |    INF |    INF |    INF |
  //| ...  |    ... |    ... |    ... |    ... |

  dp[1][0] = 0;

  for (int mask = 1; mask < totMasks; mask++) {
    for (int curCity = 0; curCity < n; curCity++) {
      if (dp[mask][curCity] == INT_MAX)
        continue;

      for (int nextCity = 0; nextCity < n; nextCity++) {
        if (mask & (1 << nextCity))
          continue;

        int nextMap = mask | (1 << nextCity);

        dp[nextMap][nextCity] = min(
            dp[nextMap][nextCity], dp[mask][curCity] + dist[curCity][nextCity]);
      }
    }
  }

  int ans = INT_MAX;
  int allVisited = totMasks - 1;

  for (int lastCity = 1; lastCity < n; lastCity++) {
    ans = min(ans, dp[allVisited][lastCity] + dist[lastCity][0]);
  }
  return ans;
};

int main() {

  vector<vector<int>> distance = {
      {0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};

  cout << "Minimum tour cost = " << heldKarp(distance);

  return 0;
}
