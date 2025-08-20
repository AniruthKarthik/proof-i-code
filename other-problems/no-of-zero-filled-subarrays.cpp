// leetcode 2348 no of zero filled sub arrays
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	long long zeroFilledSubarray(vector<int> &nums)
	{
		long long ccount = 0;
		long long ans = 0;
		for (int i : nums)
		{
			if (i == 0)
			{
				ccount++;
			}
			else
			{
				if (ccount > 0)
				{
					ans += (ccount * (ccount + 1)) / 2;
					ccount = 0;
				}
			}
		}
		ans += (ccount * (ccount + 1)) / 2;
		return ans;
	}
};
