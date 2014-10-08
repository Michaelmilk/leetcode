#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

/*����������*/
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
			//��Ϊdp[j - 1], dp[j]�ֱ��ʾ��ǰ�������Ϸ������Ϸ���ǰ��һ������ֵ
			// ��ǰ��ֵΪtriangle[i - 1][j - 1]ֻ��������������ӣ���������Ҫȡǰ
			// һ����������dp���±��1��ʼ������
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

/*����������*/
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