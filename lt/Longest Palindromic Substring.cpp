#include<iostream>
#include<string>
#include <iterator>

using namespace std;



string longestPalindrome(string s) 
{
	int size = s.size();
	bool flag[1000][1000] = { false };
	int maxlen = 1;
	int st = 0;

	for (int i = 0; i < size; i++)
	{
		flag[i][i] = true;
	}

	for (int i = 0; i < size - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			flag[i][i + 1] = true;
			maxlen = 2;
			st = i;
		}
	}
	

	for (int len = 3; len <= size; len++)
	{
		for (int start = 0; start < size - len + 1; start++)
		{
			int last = start + len - 1;

			if (s[start] == s[last] && flag[start + 1][last - 1])
			{
				flag[start][last] = true;
				st = start;
				maxlen = len;
			}
		}
	}

	return s.substr(st, maxlen);
}

int main()
{
	string str = "";//"akbbnlllm";
	cout << longestPalindrome(str) << endl;
	return 0;
}


/*exceed time
int flag[1005][1005] = {0};


string longestPalindrome(string s)
{
	string rs(s.rbegin(), s.rend());
	int size = s.size();
	
	int last = 0;
	int maxlen = 1;
	michael 

	for (int i = 0; i <= size; i++)
	{
		flag[0][i] = 0;
		flag[i][0] = 0;
	}

	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (s[i - 1] == rs[j - 1])
			{
				flag[i][j] = flag[i - 1][j - 1] + 1;
				if (maxlen < flag[i][j])
				{
					maxlen = flag[i][j];
					last = i;
				}
			}
		}
	}
	if (0 == last)
	{
		return s.substr(last, maxlen);
	}
	else
	{
		return s.substr(last - maxlen, maxlen);
	}
}

*/

/*
int main()
{
	string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string str1 = "";	cout << longestPalindrome(str1) << endl;
	return 0;
}*/