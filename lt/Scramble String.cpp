#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isScramble(string s1, string s2)
{
	if (s1 == s2)
	{
		return true;
	}

	if (s1.length() != s2.length())
	{
		return false;
	}
	
	int len = s1.length();
	/*
	定义dp[i][j][k]:
	当dp[i][j][k]=true时，表示S1[i..i+k-1] == S2[j..j+k-1]。
	dp[i][j][k]记录的是S1从i开始k个字符与S2从j开始k个字符是否为Scramble String。
	最简单的情况为k=1时，即S1[i]与S2[j]是否为Scramble String。
	因此F[i][j][1] = S1[i] == S2[j]。
	当K=2时，
	F[i][j][2] = (F[i][j][1] && F[i+1][j+1][1]) || (F[i][j+1][1] && F[i+1][j][1])。
	F[i][j][1] && F[i+1][j+1][1]表达的是 S1[i] == S2[j] && S1[i+1]==S2[j+1]
	（例如：“AC”和“AC”），如果这个条件满足，那么S1[i..i+1]与S2[j..j+1]自然为Scramble String，
	即F[i][j][2] = true。F[i][j+1][1] && F[i+1][j][1]表达的是S1[i+1] == S2[j] && S1[i] == S2[j + 1] 
	（例如： “AB”和“BA”），同样如果该条件满足，F[i][j][2] = true。
	****当K为更大的数时，同递归算法一样，我们需要枚举分割点，
	假设左边长度为l，即S[i..i+l-1]，右边长度为k-l，即S[i+l..i+k-1]。
	同样存在两种情况，S1左 = S2左 && S1右 = S2右 或者 S1左 = S2右 && S1右 = S2左
	*/
	vector<vector<vector<bool> > > dp(len, vector<vector<bool> >(len, vector<bool>(len + 1)));

	for (int k = 1; k <= len; k++)
	{
		for (int i = 0; i <= len - k; i++)
		{
			for (int j = 0; j <= len - k; j++)
			{
				if (1 == k)
				{
					dp[i][j][k] = (s1[i] == s2[j]);
				}
				else
				{
					for (int n = 1; n < k; n++)
					{
						if ((dp[i][j][n] && dp[i + n][j + n][k - n]) || (dp[i][j + k - n][n] && dp[i + n][j][k - n]))
						{
							dp[i][j][k] = true;
							break;
						}
					}
				}
			}
		}
	}

	return dp[0][0][len];
}

/*
bool isScramble(string s1, string s2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (s1.length() != s2.length()) {
		return false;
	}
	int length = s1.length();
	//bool f[length][length][length];
	vector<vector<vector<bool> > > f(length + 1, vector<vector<bool> >(length + 1, vector<bool>(length + 1)));
	//memset(f, false, sizeof(bool)* length * length * length);

	for (int k = 1; k <= length; k++) {
		for (int i = 0; i <= length - k; i++) {
			for (int j = 0; j <= length - k; j++) {
				if (k == 1) {
					f[i][j][k] = s1[i] == s2[j];
				}
				else {
					for (int l = 1; l < k; l++) {
						if ((f[i][j][l] && f[i + l][j + l][k - l]) || (f[i][j + k - l][l] && f[i + l][j][k - l])) {
							f[i][j][k] = true;
							break;
						}
					}
				}
			}
		}
	}

	return f[0][0][length];
}
*/

int main()
{
	cout << isScramble("abc", "bac") << endl;
	return 0;
}
