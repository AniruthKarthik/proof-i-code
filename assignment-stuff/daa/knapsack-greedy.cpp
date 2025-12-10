#include <bits/stdc++.h>
using namespace std;

double greedyKnapsack(int W, vector<int> &wt, vector<int> &val) {
  int n = wt.size();

  vector<array<double, 3>> items;
  // { ratio, weight, value }

  for (int i = 0; i < n; i++) {
    double ratio = (double)val[i] / wt[i];
    items.push_back({ratio, (double)wt[i], (double)val[i]});
  }

  sort(items.begin(), items.end(),
       [](auto &a, auto &b) { return a[0] > b[0]; });

  double totalValue = 0.0;

  for (int i = 0; i < n; i++) {

    double w = items[i][1];
    double v = items[i][2];

    if (W >= w) {
      W -= w;
      totalValue += v;
    } else {
      double fraction = (double)W / w;
      totalValue += v * fraction;
      break;
    }
  }

  return totalValue;
}
