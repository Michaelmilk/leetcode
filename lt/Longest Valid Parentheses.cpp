#include <iostream>
#include <string>
#include <stack>

using namespace std;

int longestValidParentheses(string s) 
{
	int size = s.length();
	int dp[1000];
	memset(dp, 0, 1000 * 4);
	int max = 0;

	for (int i = size - 2; i >= 0; i--)
	{
		if (s[i] == '(')
		{
			int j = i + 1 + dp[i + 1];

			if (j < size && s[j] == ')')
			{
				dp[i] = dp[i + 1] + 2;
				if (j + 1 < size)
				{
					dp[i] += dp[j + 1];
				}
			}

		}
		
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}
	
	return max;
}

int main()
{
	int n = longestValidParentheses("))(()())");
	cout << n << endl;
	return 0;
}