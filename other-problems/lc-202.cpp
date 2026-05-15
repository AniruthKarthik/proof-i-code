#include <unordered_set>
using namespace std;
class Solution {
public:
  bool isHappy(int n) {
    int sum = n;
    unordered_set<int> st;
    while (true) {
      sum = addsqd(sum);
      if (sum == 1)
        return true;
      if (isdup(st, sum)) {
        return false;
      }
    }
  }

  bool isdup(unordered_set<int> &st, int val) {
    if (!st.insert(val).second) {
      return true;
    }

    return false;
  }

  int addsqd(int n) {
    int sum = 0;
    while (n > 0) {
      int r = n % 10;
      n = n / 10;
      sum += r * r;
    }

    return sum;
  }
};
