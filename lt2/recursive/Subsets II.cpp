#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void solve(int idx, int size, vector<int> &S, vector<int> &buf, vector<vector<int> > &ans)
{
	ans.push_back(buf);
	if (idx >= size)
	{
		return;
	}

	for (int i = idx; i < size; i++)
	{
		if (i != idx && S[i] == S[i - 1])//相当于使用相同数字的第一个数
		{
			continue;
		}
		buf.push_back(S[i]);
		solve(i + 1, size, S, buf, ans);
		buf.pop_back();
		/*
		while (i < size - 1 && S[i] == S[i + 1])
		{
			i++;
		}
		*/
	}
}

vector<vector<int> > subsetsWithDup(vector<int> &S)
{
	vector<vector<int> > ans;
	vector<int> buf;
	int size = S.size();
	ans.push_back(buf);
	if (0 == size)
	{
		return ans;
	}
	ans.pop_back();

	sort(S.begin(), S.end());

	solve(0, size, S, buf, ans);

	return ans;
}

int  main()
{
	vector<int> v = { 1, 2, 2 };
	vector<vector<int> > ans = subsetsWithDup(v);

	int size = ans.size();
	for (int i = 0; i < size; i++)
	{
		copy(ans[i].begin(), ans[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}