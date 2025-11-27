#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &vec)
{
	for (int i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}
