#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v = {20, 30, 60, 10};
  int n = v.size();

  vector<vector<long long>> memo(n, vector<long long>(n, -1));
  vector<vector<char>> pick(n, vector<char>(n, 0));

  function<long long(int, int)> f = [&](int L, int R) -> long long {
    if (L > R)
      return 0;
    if (memo[L][R] != -1)
      return memo[L][R];
    if (L == R) {
      pick[L][R] = 1;
      return memo[L][R] = v[L];
    }

    int a1 = L + 1, b1 = R;
    if (a1 <= b1) {
      if (v[a1] >= v[b1])
        a1++;
      else
        b1--;
    }
    long long leftVal = v[L] + f(a1, b1);

    int a2 = L, b2 = R - 1;
    if (a2 <= b2) {
      if (v[a2] >= v[b2])
        a2++;
      else
        b2--;
    }
    long long rightVal = v[R] + f(a2, b2);

    if (leftVal >= rightVal) {
      pick[L][R] = 1;
      return memo[L][R] = leftVal;
    }
    pick[L][R] = 0;
    return memo[L][R] = rightVal;
  };

  long long total = f(0, n - 1);

  vector<int> path;
  int L = 0, R = n - 1;

  while (L <= R) {
    if (L == R) {
      path.push_back(v[L]);
      break;
    }
    if (pick[L][R]) {
      path.push_back(v[L]);
      int x = L + 1, y = R;
      if (v[x] >= v[y])
        x++;
      else
        y--;
      L = x;
      R = y;
    } else {
      path.push_back(v[R]);
      int x = L, y = R - 1;
      if (v[x] >= v[y])
        x++;
      else
        y--;
      L = x;
      R = y;
    }
  }

  for (int k : path)
    cout << k << " ";
  cout << "\n" << total;
}
