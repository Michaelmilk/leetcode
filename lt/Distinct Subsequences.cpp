#include <iostream>
#include <vector>
#include <string>

using namespace std;

//���������ַ���S��T������S������ɾ�����е�������(����0)�ַ���
//ʹ��õ�T�����ж�����ɾ�����Եõ�T��(����S�������Ӵ�����T��ͬ���ж��ٸ�)

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