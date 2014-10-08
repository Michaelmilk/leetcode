#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void solve(int idx, int n, int k, vector<int> &buf, vector<vector<int> > &ans)
{
	if (buf.size() == k)
	{
		ans.push_back(buf);
		return;
	}

	for (int i = idx; i <= n; i++)
	{
		buf.push_back(i);
		solve(i + 1, n, k, buf, ans);
		buf.pop_back();
	}
}

vector<vector<int> > combine(int n, int k)
{
	vector<vector<int> > ans;
	if (0 == k)
	{
		return ans;
	}
	int idx = 1;
	solve(idx, n, k, vector<int>(), ans);

	return ans;
}

int  main()
{
	vector<vector<int> > ans = combine(4, 0);

	int size = ans.size();
	for (int i = 0; i < size; i++)
	{
		copy(ans[i].begin(), ans[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}