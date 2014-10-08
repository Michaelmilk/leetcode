#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectArea(vector<int> height)
{
	int size = height.size();
	height[size - 1] = -1;
	int maxArea = 0;
	int idx = 0;
	stack<int> stk;

	while (idx < size)
	{
		if (stk.empty() || height[idx] >= height[stk.top()])
		{
			stk.push(idx++);
		}
		else
		{
			int i = stk.top();
			stk.pop();
			int curArea = height[i] * (stk.empty() ? idx : idx - stk.top() - 1);
			maxArea = maxArea > curArea ? maxArea : curArea;
		}
	}

	return maxArea;
}

int maximalRectangle(vector<vector<char> > &matrix)
{
	int maxArea = 0;
	int rowSize = matrix.size();
	if (0 == rowSize)
	{
		return 0;
	}
	int colSize = matrix[0].size();
	if (0 == colSize)
	{
		return 0;
	}
	/*
	/*相当于dp[i][j],表示第j列的第i行到第j列的第一行的路径上1的个数*/
	vector<vector<int> > dp(rowSize, vector<int>(colSize + 1));

	for (int i = 0; i < colSize; i++)
	{
		if ('1' == matrix[0][i])
		{
			dp[0][i] = 1;
		}
	}

	for (int i = 1; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			if ('1' == matrix[i][j])
			{
				dp[i][j] = dp[i - 1][j] + 1;
			}
		}
	}

	for (int i = 0; i < rowSize; i++)
	{
		int curArea = largestRectArea(dp[i]);
		maxArea = maxArea > curArea ? maxArea : curArea;
	}

	return maxArea;
}

int main()
{
	vector<vector<char> > matrix = { { '0' } };
	cout << maximalRectangle(matrix) << endl;
	return 0;
}