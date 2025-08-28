#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution {
  public:
	vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
	{

		int h = grid.size();
		int l = grid[0].size();

		for (int a = 0; a < h; a++)
		{
			int i = a;
			int j = 0;
			vector<int> tobesorted;
			while (i < h && j < l)
			{
				tobesorted.push_back(grid[i][j]);
				i++;
				j++;
			}
			sort(tobesorted.begin(), tobesorted.end(), greater<int>());
			int x = 0;
			i = a;
			j = 0;
			while (i < h && j < l)
			{
				grid[i][j] = tobesorted[x++];
				i++;
				j++;
			}
		}

		for (int b = 1; b < l; b++)
		{
			int i = 0;
			int j = b;
			vector<int> tobesorted;
			while (i < h && j < l)
			{
				tobesorted.push_back(grid[i][j]);
				i++;
				j++;
			}
			sort(tobesorted.begin(), tobesorted.end());
			int x = 0;
			i = 0;
			j = b;
			while (i < h && j < l)
			{
				grid[i][j] = tobesorted[x++];
				i++;
				j++;
			}
		}

		return grid;
	}
};
