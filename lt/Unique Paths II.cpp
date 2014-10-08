#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
	int m = obstacleGrid.size();

	if (0 == m)
	{
		return 0;
	}
	
	int n = obstacleGrid[0].size();
	vector<vector<int> > dp(m, vector<int>(n));

	for (int i = 0; i < m && obstacleGrid[i][0] != 1; i++)
	{
		dp[i][0] = 1;
	}
	for (int i = 0; i < n && obstacleGrid[0][i] != 1; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (obstacleGrid[i][j] == 1)
			{
				continue;
			}
			else if (obstacleGrid[i][j] != 1 && obstacleGrid[i][j - 1] != 1 && obstacleGrid[i - 1][j] == 1)
			{
				dp[i][j] = dp[i][j - 1];
			}
			else if (obstacleGrid[i][j] != 1 && obstacleGrid[i - 1][j] != 1 && obstacleGrid[i][j - 1] == 1)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else if (obstacleGrid[i][j] != 1 && obstacleGrid[i][j - 1] != 1 && obstacleGrid[i - 1][j] != 1)
			{
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
	}
	return dp[m - 1][n - 1];
}

int main()
{
	return 0;
}