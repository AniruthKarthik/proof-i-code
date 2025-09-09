// 4 SEPTEMBER 2025
// REMOVE DUPLICATES IN THE GIVEN SORTED VECTOR (N)
#include "printer.hpp"
#include <climits>
#include <vector>
using namespace std;

void remove_dupes(vector<int> &vec)
{
	int temp = INT_MIN;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == temp)
		{
			vec.erase(vec.begin() + i);
			i--;
		}
		temp = vec[i];
	}
};

int main()
{
	vector<int> vec = {2, 2, 2, 2, 2, 2, 3, 3, 4, 5, 6, 7, 7};
	print_vector(vec);
	remove_dupes(vec);
	print_vector(vec);

	return 0;
}
