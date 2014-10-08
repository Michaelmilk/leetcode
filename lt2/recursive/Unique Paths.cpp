#include <iostream>
#include <vector>

using namespace std;

/*
void solve(int row, int col, int m, int n, int &ans)
{
	if (row == m && col == n)
	{
		ans += 1;
		return;
	}

	if (row < m)
	{
		solve(row + 1, col, m, n, ans);
	}
	
	if (col < n)
	{
		solve(row, col + 1, m, n, ans);
	}
	
}

int uniquePaths(int m, int n)
{
	int ans = 0;
	if (0 == m && 0 == n)
	{
		return ans;
	}

	//因为该问题会有这样一种情况，当row=m的时候，在开始遍历col，
	//所以rowh和col初始值为1比较好
	int row = 1;
	int col = 1;
	solve(row, col, m, n, ans);
	
	return ans;
}
*/
vector<vector<int> > dp(100, vector<int>(100));
/*
int uniquePaths(int m, int n)
{
	if (1 == m && 1 == n)
	{
		return 1;
	}

	if (dp[m][n] != 0)
	{
		return dp[m][n];
	}
	else if (1 == n)
	{
		dp[m][n] = uniquePaths(m - 1, n);
	}
	else if (1 == m)
	{
		dp[m][n] = uniquePaths(m, n - 1);
	}
	else
	{
		dp[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}

	return dp[m][n];
}
*/
int uniquePaths(int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}
int main()
{
	cout << uniquePaths(2, 2) << endl;
	return 0;
}