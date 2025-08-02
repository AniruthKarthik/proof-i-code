// **Given `n` steps, count how many distinct ways you can climb to the top if
// you can take 1 or 2 steps at a time.**

#include <iostream>
int climbStairs(int n)
{
	if (n == 0 || n == 1)
		return 1;
	int onestep = climbStairs(n - 1);
	int twostep = 0;
	if (n > 1)
	{
		twostep = climbStairs(n - 2);
	}
	return onestep + twostep;
}

int main()
{
	std::cout << climbStairs(5);
	return 0;
}
