#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

/*从上往下求法*/
/*
int minimumTotal(vector<vector<int> > &triangle)
{
	int size = triangle.size();
	vector<int> dp(size + 1, INT_MAX);
	dp[1] = triangle[0][0];
	for (int i = 2; i <= size; i++)
	{
		for (int j = i; j > 0; j--)
		{
			//因为dp[j - 1], dp[j]分别表示当前数字正上方和正上方的前面一个数的值
			// 当前的值为triangle[i - 1][j - 1]只能与这两个数相加，鱿鱼这里要取前
			// 一个数，所以dp的下标从1开始！！！
			dp[j] = min(dp[j - 1], dp[j]) + triangle[i - 1][j - 1];
		}
	}
	
	int min = INT_MAX;
	for (int i = 1; i <= size; i++)
	{
		min = min < dp[i] ? min : dp[i];
	}
	
	return min;
}*/

/*从下往上求法*/
int minimumTotal(vector<vector<int> > &triangle)
{
	int size = triangle.size();
	vector<int> dp(triangle[size - 1]);

	while (size--)
	{
		for (int i = 0; i < size; i++)
		{
			dp[i] = min(dp[i], dp[i + 1]) + triangle[size - 1][i];
		}
	}
	
	return dp[0];
}