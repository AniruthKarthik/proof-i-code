// 5 SEPTEMBER 2025
// FIND THE UPPER AND LOWER BOUND OF THE GIVEN ELEMENT IN A SORTED ARRAY (LOGn)
#include "printer.hpp"
#include <iostream>
#include <vector>
using namespace std;

struct Sol
{
	int lbound, ubound;
};

int binary_search(vector<int> &vec, int x, int lo, int hi)
{
	int mid = (lo + hi) / 2;
	if (lo > hi)
		return -1;
	if (vec[mid] == x)
		return mid;
	if (vec[mid] > x)
		return binary_search(vec, x, lo, mid - 1);
	else
		return binary_search(vec, x, mid + 1, hi);
}

Sol find_bounds(vector<int> &vec, int x)
{
	int firstloc = binary_search(vec, x, 0, vec.size() - 1);
	int lb = firstloc;
	int ub = firstloc;
	while (ub < vec.size() - 1 && vec[ub + 1] == x)
	{
		ub = binary_search(vec, x, ub + 1, vec.size() - 1);
	}
	while (lb > 0 && vec[lb - 1] == x)
	{
		lb = binary_search(vec, x, 0, lb - 1);
	}
	return {lb, ub};
}
int main()
{
	vector<int> vec = {1, 1, 1, 1, 2, 2, 2, 3};
	print_vector(vec);
	Sol sol = find_bounds(vec, 1);
	cout << sol.lbound << " " << sol.ubound;
	return 0;
}
