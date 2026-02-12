#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    int start, end = 0;
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    start = intervals[0][0];
    end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] <= end) {
        end = max(end, intervals[i][1]);
      } else {
        res.push_back({start, end});
        start = intervals[i][0];
        end = intervals[i][1];
      }
    }

    res.push_back({start, end});

    return res;
  }
};
