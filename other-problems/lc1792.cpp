// NOT OPTIMIZED

#include <queue>
#include <vector>
using namespace std;
struct cmp
{
	bool operator()(const vector<int> &a, const vector<int> &b)
	{
		double gainA = (double)(a[0] + 1) / (a[1] + 1) - (double)a[0] / a[1];
		double gainB = (double)(b[0] + 1) / (b[1] + 1) - (double)b[0] / b[1];
		return gainA < gainB; // max heap by gain
	}
};

class Solution {
  public:
	double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
	{
		double result = 0;
		priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
		for (vector<int> vec : classes)
		{
			pq.push(vec);
		}
		while (extraStudents > 0)
		{
			vector<int> temp = pq.top();
			pq.pop();
			temp[0]++;
			temp[1]++;
			extraStudents--;
			pq.push(temp);
		}
		while (!pq.empty())
		{
			vector<int> temp = pq.top();
			pq.pop();
			result += (double)temp[0] / temp[1];
		}

		return result / classes.size();
	}
};
