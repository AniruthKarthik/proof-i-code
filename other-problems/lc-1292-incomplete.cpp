#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    for (vector vec : mat) {
      int n = vec.size();
      int last = 0;
      int sum = 0;
      int len = 0;
      for (int i = 0; i < n; i++) {
        sum += vec[i];
        len = max(len, i - last + 1);
        if (sum > threshold) {
          do {
            sum -= vec[last];
            len = max(len, i - last + 1);
            last++;
          } while (sum >= threshold);
        }
      }
    }
  }
};
