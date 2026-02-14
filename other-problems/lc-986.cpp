#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    int na = firstList.size();
    int nb = secondList.size();
    int i = 0;
    int j = 0;
    vector<vector<int>> res;
    while (i < na && j < nb) {
      int cs = max(firstList[i][0], secondList[j][0]);
      int ce = min(firstList[i][1], secondList[j][1]);
      if (cs <= ce)
        res.push_back({cs, ce});
      if (firstList[i][1] < secondList[j][1])
        i++;
      else
        j++;
    }
    return res;
  }
};
