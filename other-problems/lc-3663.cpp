#include <climits>
using namespace std;

class Solution {
  public:
	int getLeastFrequentDigit(int n)
	{
		int frq[10] = {0};

		if (n == 0)
			frq[0] = 1;
		while (n > 0)
		{
			int d = n % 10;
			frq[d]++;
			n /= 10;
		}
		int mini = INT_MAX;
		int res = -1;
		for (int i = 0; i < 10; i++)
		{
			if (frq[i] > 0 && frq[i] < mini)
			{
				mini = frq[i];
				res = i;
				;
			}
		}

		return res;
	}
};
