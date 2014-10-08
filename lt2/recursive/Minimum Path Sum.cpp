#include <iostream>
#include <vector>

using namespace std;

int dp[105][105];

int minPathSum(vector<vector<int> > &grid)
{
	int rSize = grid.size();
	if (0 == rSize)
	{
		return 0;
	}

	int cSize = grid[0].size();
	memset(dp, 0, sizeof(dp));
	dp[0][0] = grid[0][0];
	for (int i = 1; i < rSize; i++)
	{
		dp[i][0] = grid[i][0] + dp[i - 1][0];
	}

	for (int i = 1; i < cSize; i++)
	{
		dp[0][i] = grid[0][i] + dp[0][i - 1];
	}

	for (int i = 1; i < rSize; i++)
	{
		for (int j = 1; j < cSize; j++)
		{
			if (dp[i - 1][j] < dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j] + grid[i][j];
			}
			else
			{
				dp[i][j] = dp[i][j - 1] + grid[i][j];
			}
		}
	}

	return 	dp[rSize - 1][cSize - 1];
}

int main()
{
	vector<int> v = { 1 };
	vector<vector<int> > ans;
	ans.push_back(v);
	cout << minPathSum(ans) << endl;
	return 0;
}