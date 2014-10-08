#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
	int len1 = s1.length();
	int len2 = s2.length();
	int len3 = s3.length();

	if (len1 + len2 != len3)
	{
		return false;
	}
	/*dp[i][j]表示s3中的前i+j（个）字符由s1的前i个字符和s2中的前j个字符组成*/
	bool dp[1000][1000];
	dp[0][0] = true;

	for (int i = 1; i <= len1; i++)
	{
		dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];//确定S3的前n个字符来自哪个字串（s1或s2），并且相应的数组位置值设为true
	}

	for (int j = 1; j <= len2; j++)
	{
		dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];//确定S3的前n个字符来自哪个字串（s1或s2），并且相应的数组位置值设为true
	}

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			/*
			dp[i][j]表示s3中的前i+j（个）字符由s1的前i个字符和s2中的前j个字符组成；
				dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]：
				dp[i - 1][j] == true表示s3中的前i+j-1（个）字符由s1的前i-1个字符和s2中的前j个字符组成
				并且s1的第i个字符（即s1[i-1]）与s3的第i + j个字符（即s3[i + j - 1]）相等。
				dp[i][j - 1] && s2[i - 1] == s3[i + j - 1]：
				dp[i][j - 1] == true表示s3中的前i+j-1（个）字符由s1的前i个字符和s2中的前j-1个字符组成
				并且s2的第j个字符（即s2[j-1]）与s3的第i + j个字符（即s3[i + j - 1]）相等。
			*/
			dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
		}
	}

	return dp[len1][len2];
}