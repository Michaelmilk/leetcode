#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int minPathSum(vector<vector<int> > &grid)
{
	int m = grid.size();
	if (0 == m)
	{
		return 0;
	}

	int n = grid[0].size();

	vector<vector<int> > dp(m, vector<int>(n, 0));
	dp[0][0] = grid[0][0];

	for (int i = 1; i < m; i++)
	{
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	}
	
	for (int j = 1; j < n; j++)
	{
		dp[0][j] = dp[0][j - 1] + grid[0][j];
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}
	
	return dp[m - 1][n - 1];
}

int main()
{
	vector<vector<int> > v = { { 1, 2 }, { 1, 1 } };
	int ans = minPathSum(v);
	cout << ans << endl;
	return 0;
}