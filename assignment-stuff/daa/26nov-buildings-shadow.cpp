// Given a list of rectangular buildings defined by their bottom-left and
// top-right coordinates, calculate the total shadow area projected by these
// buildings. Buildings may overlap, but overlapping regions should be counted
// only once. The algorithm processes rectangles in left-to-right order,
// subtracts overlapping areas between consecutive rectangles, and adjusts the
// next rectangle to account for remaining uncovered portions, ultimately
// computing the union of all building areas without double-counting.

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using build = pair<pair<int, int>, pair<int, int>>;

struct pqorder {
  bool operator()(const build &a, const build &b) {
    return a.first.first > b.first.first;
  }
};

priority_queue<build, vector<build>, pqorder> getpq() {
  return priority_queue<build, vector<build>, pqorder>(
      pqorder(), vector<build>{{{0, 0}, {2, 2}},
                               {{1, 1}, {4, 5}},
                               {{3, 0}, {6, 3}},
                               {{5, 2}, {9, 7}},
                               {{2, 4}, {7, 9}},
                               {{8, 1}, {10, 4}},
                               {{0, 5}, {3, 8}},
                               {{4, 6}, {6, 10}},
                               {{7, 7}, {11, 11}},
                               {{1, 9}, {4, 12}}});
}

float getArea(const build &r) {
  return float((r.second.first - r.first.first) *
               (r.second.second - r.first.second));
}

int main() {
  auto pq = getpq();
  float area = 0;

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    float curea = getArea(cur);

    if (!pq.empty()) {
      auto next = pq.top();
      pq.pop();

      int ox1 = max(cur.first.first, next.first.first);
      int oy1 = max(cur.first.second, next.first.second);
      int ox2 = min(cur.second.first, next.second.first);
      int oy2 = min(cur.second.second, next.second.second);

      if (ox1 < ox2 && oy1 < oy2) {
        curea -= getArea({{ox1, oy1}, {ox2, oy2}});

        next.first.first = max(next.first.first, cur.second.first);
      }

      pq.push(next);
    }

    area += curea;
  }
  cout << "shadow area -> " << area << endl;
  return 0;
}
