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
	����dp[i][j][k]:
	��dp[i][j][k]=trueʱ����ʾS1[i..i+k-1] == S2[j..j+k-1]��
	dp[i][j][k]��¼����S1��i��ʼk���ַ���S2��j��ʼk���ַ��Ƿ�ΪScramble String��
	��򵥵����Ϊk=1ʱ����S1[i]��S2[j]�Ƿ�ΪScramble String��
	���F[i][j][1] = S1[i] == S2[j]��
	��K=2ʱ��
	F[i][j][2] = (F[i][j][1] && F[i+1][j+1][1]) || (F[i][j+1][1] && F[i+1][j][1])��
	F[i][j][1] && F[i+1][j+1][1]������� S1[i] == S2[j] && S1[i+1]==S2[j+1]
	�����磺��AC���͡�AC�������������������㣬��ôS1[i..i+1]��S2[j..j+1]��ȻΪScramble String��
	��F[i][j][2] = true��F[i][j+1][1] && F[i+1][j][1]�������S1[i+1] == S2[j] && S1[i] == S2[j + 1] 
	�����磺 ��AB���͡�BA������ͬ��������������㣬F[i][j][2] = true��
	****��KΪ�������ʱ��ͬ�ݹ��㷨һ����������Ҫö�ٷָ�㣬
	������߳���Ϊl����S[i..i+l-1]���ұ߳���Ϊk-l����S[i+l..i+k-1]��
	ͬ���������������S1�� = S2�� && S1�� = S2�� ���� S1�� = S2�� && S1�� = S2��
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