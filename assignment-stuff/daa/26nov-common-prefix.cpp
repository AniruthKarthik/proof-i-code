// Given a vector of strings, find the longest common prefix shared by all the
// strings. The algorithm compares characters of the current longest prefix with
// each string and updates the prefix length accordingly, finally returning the
// prefix that is common to all strings in the list.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

  vector<string> strs = {"ramakrr", "ramadefw", "ramafreefe", "rawfef"};

  string maxstr = strs[0];

  int maxi = maxstr.size();

  for (int i = 1; i < strs.size(); i++) {
    for (int j = 0; j < maxi; j++) {
      if (maxstr.substr(0, j) != strs[i].substr(0, j))
        maxi = j - 1;
    }
  }

  cout << maxstr.substr(0, maxi);
}
