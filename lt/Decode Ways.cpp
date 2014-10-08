#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(string s) 
{
	int len = s.length();
	
	if (s[0] == '0' || 0 == len)
	{
		return 0;
	}

	vector<int> dp(len + 1, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 1; i < len; i++)
	{
		if (s[i] >= '1')//10的情况下，0不能单独成为一个单词字母
		{
			dp[i + 1] = dp[i];
		}
		string ans(s, i - 1, 2);
		if (('0' == s[i] && ans >= "26") || ans == "00")//1250, 1000
		{
			return 0;
		}
		if (ans <= "26" && ans[0] != '0')//1010中的01的情况
		//if (ans <= "26")//"1010"中的"01"<="26"
		{
			dp[i + 1] += dp[i - 1];
		}
	}
	return dp[len];
}

int main()
{
	cout << numDecodings("1010") << endl;
}