#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string solution(string str, int k) {
  unordered_map<char, int> cnts;
  for (char c : str) {
    cnts[c]++;
  }
  int st = 0;
  string res = "";
  for (int i = 0; i < str.length(); i++) {
    res += '-';
  }

  for (auto c : cnts) {
    if (res[st] == '-') {
      for (int i = st; i < res.size() && i < (c.second * k) + 1; i += k) {
        res[i] = c.first;
      }
    }
    do {
      st++;
    } while (st < res.size() && res[st] != '-');
  }

  return res;
}

int main() {
  string s = "aaccjj";
  string a = solution(s, 3);
  cout << a;
}
