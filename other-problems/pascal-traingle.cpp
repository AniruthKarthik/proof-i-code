// n levels of pascal triangle

#include <array>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pascal(int n)
{
	vector<vector<int>> result = {};
	vector<int> vec;
	if (n == 0)
		return result;
	for (int i = 1; i <= n; i++)
	{
		vector<int> temp = {};
		if (i == 1)
		{
			vec = {1};
			result.push_back(vec);
			continue;
		}
		temp.push_back(1);
		for (int i = 0; i < vec.size() - 1; i++)
		{
			temp.push_back(vec[i] + vec[i + 1]);
		}
		temp.push_back(1);
		vec = temp;
		result.push_back(temp);
	}

	return result;
};

int main()
{
	vector<vector<int>> ans = pascal(5);
	for (vector<int> i : ans)
	{
		for (int j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}
