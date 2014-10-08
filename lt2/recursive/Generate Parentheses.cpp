#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

void solve(int left, int right, int n, string buf, vector<string> &ans)
{
	if (left == n && right == n)
	{
		ans.push_back(buf);
		return;
	}

	if (left < n)
	{
		//buf += "(";
		solve(left + 1, right, n, buf + "(", ans);
		//buf.pop_back();
	}

	if (right < left)
	{
		//buf += ")";
		solve(left, right + 1, n, buf + ")", ans);
		//buf.pop_back();
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string>  ans;

	solve(0, 0, n, "", ans);

	return ans;
}

int main()
{
	vector<string> ans = generateParenthesis(3);
	copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	return 0;
}