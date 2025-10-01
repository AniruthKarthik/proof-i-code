#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  public:
	int score(vector<string> &cards, char x)
	{
		int same = 0;
		int one = 0;
		for (auto i : cards)
		{
			if (i[0] == x && i[1] == x)
			{
				same++;
				continue;
			}
			if (i[0] == x || i[1] == x)
			{
				one++;
				continue;
			}
		}
		if (same > one + two)
		{
			int a = gcd(same, one + two);
			same -= a;
			return a + (same / 2);
		}
		return gcd(same, one + two);
	}
};
