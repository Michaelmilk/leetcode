#include <iostream>
#include <string>

using namespace std;

void solve(int idx, int n, string &ans)
{
	if (n == idx)
	{
		return;
	}
	int len = ans.length();
	int count = 1;
	string buf;
	for (int i = 0; i < len; i++)
	{
		if (i + 1 < len && ans[i] == ans[i + 1])
		{
			count++;
		}
		else
		{
			buf += count + 48;
			buf += ans[i];
			count = 1;
		}
		
	}
	ans = buf;
	solve(idx + 1, n, ans);
}

string countAndSay(int n)
{
	string ans = "1";

	solve(1, n, ans);

	return ans;
}

int main()
{
	string ans = countAndSay(2);
	cout << ans << endl;
	return 0;
}