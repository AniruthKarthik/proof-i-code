#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int getArea(int x1, int y1, int x2, int y2) { return (x2 - x1) * (y2 - y1); }

  int area = 0;

  int rectangleArea(vector<vector<int>> &rectangles) {
    sort(
        rectangles.begin(), rectangles.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    for (int i = 0; i < rectangles.size() - 1; i++) {
      int fx1 = rectangles[i][0];
      int fy1 = rectangles[i][1];
      int fx2 = rectangles[i][2];
      int fy2 = rectangles[i][3];

      area + = getArea(fx1, fy1, fx2, fy2);
    }
  }
};
