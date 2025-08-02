// aim for max profit, can steal at adjacent houses

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &vec)
{
	int n = vec.size();
	if (n == 0)
		return 0;
	if (n == 1)
		return vec[0];
	for (int i = 2; i < n; i++)
	{
		int maxval = 0;
		for (int j = 0; j < i - 1; j++)
		{
			maxval = max(maxval, vec[j]);
		}
		vec[i] += maxval;
	}
	return max(vec[n - 2], vec[n - 1]);
}

int main()
{
	vector<int> vec = {2, 7, 9, 3, 1};
	cout << rob(vec);
}
