#include <iostream>
#include <vector>

using namespace std;
/*
int dp[101][101];

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
	int rSize = obstacleGrid.size();
	if (0 == rSize)
	{
		return 0;
	}

	int cSize = obstacleGrid[0].size();
	for (int i = 0; i < rSize; i++)
	{
		if (obstacleGrid[i][0] == 0)
		{
			dp[i][0] = 1;
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < cSize; i++)
	{
		if (obstacleGrid[0][i] == 0)
		{
			dp[0][i] = 1;
		}
		else
		{
			break;
		}
	}

	for (int i = 1; i < rSize; i++)
	{
		for (int j = 1; j < cSize; j++)
		{
			if (obstacleGrid[i][j] == 0)
			{
				if (obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j - 1] == 0)
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else if (obstacleGrid[i - 1][j] != 0 && obstacleGrid[i][j - 1] == 0)
				{
					dp[i][j] = dp[i][j - 1];
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
			
		}
	}
	return dp[rSize - 1][cSize - 1];
}
*/
int dp[101][101];

int solve(int rSize, int cSize, int obstacleGrid[][18])//vector<vector<int> > &obstacleGrid)
{
	if (obstacleGrid[rSize - 1][cSize - 1])
	{
		return 0;
	}

	if (1 == rSize && 1 == cSize)
	{
		return 1;
	}

	if (dp[rSize][cSize] != -1)
	{
		return dp[rSize][cSize];
	}
	else if (1 == cSize)
	{
		dp[rSize][cSize] = solve(rSize - 1, cSize, obstacleGrid);
	}
	else if (1 == rSize)
	{
		dp[rSize][cSize] = solve(rSize, cSize - 1, obstacleGrid);
	}
	else
	{
		dp[rSize][cSize] = solve(rSize - 1, cSize, obstacleGrid) + solve(rSize, cSize - 1, obstacleGrid);
	}

	return dp[rSize][cSize];
}

int uniquePathsWithObstacles2(int obstacleGrid[][18])//(vector<vector<int> > &obstacleGrid)
{
	//int rSize = obstacleGrid.size();
	/*if (0 == rSize)
	{
		return 0;
	}*/

	//int cSize = obstacleGrid[0].size();
	//memset(dp, -1, sizeof(dp) / sizeof(int));
	//return solve(rSize, cSize, obstacleGrid);
	int ans = solve(29, 18, obstacleGrid);
	return ans;
}

int main()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			dp[i][j] = -1;
		}
	}
	int a[][18] = {
		{0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
		{0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0},
		{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
		{1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
		{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}
	};

	cout << uniquePathsWithObstacles2(a) << endl;

	/*int b[19][20];
	memset(b, '1', sizeof(b));
	cout << sizeof(b) / sizeof(int) << endl;
	cout << b[5][6] << endl;*/
}
