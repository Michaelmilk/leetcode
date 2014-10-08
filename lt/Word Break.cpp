#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict)
{
	int len = s.length();
	vector <bool> dp(len, false);

	for (int i = 0; i < len; i++)
	{
		dp[i] = (dict.find(s.substr(0, i + 1)) != dict.end()) ? true : false;
		if (dp[i])
		{
			continue;
		}
		else
		{
			for (int j = 0; j < i; j++)
			{
				dp[i] = (dict.find(s.substr(j + 1, i - j)) != dict.end()) ? true : false | dp[i];
				/*dp[i] = (dict.find(s.substr(j + 1, i - j)) != dict.end()) ? true : false;
				if (dp[i])
				{
					break;
				}*/
			}
		}
	}
}