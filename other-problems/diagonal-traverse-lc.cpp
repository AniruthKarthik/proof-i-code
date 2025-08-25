// leetcode 498

class Solution {
  public:
	vector<int> findDiagonalOrder(vector<vector<int>> &mat)
	{
		vector<int> result;
		int l = mat[0].size();
		int h = mat.size();
		int i = 0, j = 0;
		int up = 1, down = 0;

		while (true)
		{
			result.push_back(mat[i][j]);
			if (i == h - 1 && j == l - 1)
				break;

			if (up)
			{
				// no top
				if (i - 1 < 0 && j + 1 < l)
				{
					j++;
					up = 0;
					down = 1;
				}
				// go diag
				else if (i - 1 >= 0 && j + 1 < l)
				{
					i--;
					j++;
				}
				// no right
				else if (i + 1 < h)
				{
					i++;
					up = 0;
					down = 1;
				}
			}
			else if (down)
			{
				// move diag
				if (i + 1 < h && j - 1 >= 0)
				{
					i++;
					j--;
				}
				// no left
				else if (i + 1 < h)
				{
					i++;
					up = 1;
					down = 0;
				}
				// no bottom
				else if (j + 1 < l)
				{
					j++;
					up = 1;
					down = 0;
				}
			}
		}
		return result;
	}
};
