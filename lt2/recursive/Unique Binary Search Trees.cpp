#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n)
{
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		int left = 0;
		while (left < i)
		{
			dp[i] += dp[left] * dp[i - 1 - left];
			left++;
		}
	}

	return dp[n];
}

int main()
{
	cout << numTrees(3) << endl;
	return 0;
}