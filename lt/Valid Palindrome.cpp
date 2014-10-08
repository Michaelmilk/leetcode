#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

bool isPalindrome(string s)
{
	if (s.empty())
	{
		return true;
	}

	string ans;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (isalpha(s[i]) || isdigit(s[i]))
		{
			if (s[i] >= 'A' && s[i] <= 'z')
			{
				ans += toupper(s[i]);
			}
			else
			{
				ans += s[i];
			}
		}
	}

	len = ans.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (ans[i] != ans[len - 1 - i])
		{
			return false;
		}
	}

	return true;
}