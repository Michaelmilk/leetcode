#include <iostream>
#include <vector>
#include <string>

using namespace std;

//给定两个字符串S，T，对于S，可以删除其中的任意多个(包括0)字符，
//使其得到T。问有多少种删法可以得到T。(或者S的所有子串中与T相同的有多少个)

int numDistinct(string S, string T)
{
	int lenS = S.length();
	int lenT = T.length();

	if (lenS < lenT)
	{
		return 0;
	}
	
	vector<vector<int> > dp(lenS + 1, vector<int>(lenT + 1, 0));

	for (int i = 0; i < lenS; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i <= lenS; i++)
	{
		for (int j = 1; j <= lenT; j++)
		{
			if (S[i - 1] == T[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	return dp[lenS][lenT];
}