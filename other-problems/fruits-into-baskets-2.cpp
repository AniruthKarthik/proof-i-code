#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

static void print_vec(vector<int> vec)
{
	for (int i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}

class Solution {
  public:
	void quick_sort(std::vector<int> &arr, int left, int right)
	{
		if (left >= right)
			return;
		int pivot = arr[right];
		int i = left - 1;
		for (int j = left; j < right; ++j)
		{
			if (arr[j] <= pivot)
				std::swap(arr[++i], arr[j]);
		}
		std::swap(arr[i + 1], arr[right]);
		quick_sort(arr, left, i);
		quick_sort(arr, i + 2, right);
	}
	int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
	{
		int n = fruits.size();
		if (n == 0)
			return 0;
		int rem = 0;
		quick_sort(fruits, 0, fruits.size() - 1);
		quick_sort(baskets, 0, baskets.size() - 1);
		print_vec(fruits);
		print_vec(baskets);
		for (int i = 0; i < n; i++)
		{
			if (baskets[i] < fruits[i])
			{
				rem += fruits[i] - baskets[i];
			}
		}
		return rem;
	}
};
int main()
{
	vector<int> fruits = {4, 2, 5};
	vector<int> baskets = {3, 5, 4};

	Solution sol;
	cout << sol.numOfUnplacedFruits(fruits, baskets);

	return 0;
}
