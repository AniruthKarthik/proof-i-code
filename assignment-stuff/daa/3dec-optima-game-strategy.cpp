#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int getMaxIndex(const vector<int> &a) {
  int n = a.size();
  if (a[0] > a[n - 1]) {
    return 0;
  } else {
    return n - 1;
  }
}

pair<int, vector<int>> brute(vector<int> a, int my, vector<int> sol,
                             bool isme) {
  int n = a.size();
  if (a.size() == 1) {
    if (isme) {
      sol.push_back(a[0]);
    }
    return {my + (isme ? a[0] : 0), sol};
  }
  if (a.size() == 2) {
    int c = max(a[0], a[1]);
    if (isme) {
      sol.push_back(c);
    }
    return {my + (isme ? c : 0), sol};
  }

  if (!isme) {
    a.erase(a.begin() + getMaxIndex(a));
    return brute(a, my, sol, true);
  }
  vector<int> a1(a.begin() + 1, a.end());
  vector<int> a2(a.begin(), a.end() - 1);
  vector<int> sol1 = sol;
  sol1.push_back(a[0]);
  vector<int> sol2 = sol;
  sol2.push_back(a[n - 1]);
  auto s1 = brute(a1, my + a[0], sol1, false);
  auto s2 = brute(a2, my + a[n - 1], sol2, false);
  if (s1.first > s2.first) {
    return s1;
  } else {
    return s2;
  }
}

int main() {
  vector<int> choices = {20, 30, 60, 10};

  vector<int> sol = {};
  auto ans = brute(choices, 0, sol, true);

  sol = ans.second;

  cout << "choices" << endl;
  for (int i : sol) {
    cout << i << " , ";
  }
  cout << "score" << endl;
  cout << ans.first;

  return 0;
}
