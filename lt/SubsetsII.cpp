#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


void solve(vector<int> tmp, vector<vector<int> >&ret, int cur, vector<int> &s, int size)
{
	if (tmp.size() > 1)
	{
		int size = ret.size();
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			if (ret[i] == tmp)
			{
				flag = true;
			}
		}

		if (!flag)
		{
			ret.push_back(tmp);
		}

		//v.clear();
		if (tmp.size() >= size - 1)
		{
			return;
		}
	}

	for (int i = cur; i < size; i++)
	{
		vector<int> v(tmp);
		v.push_back(s[i]);
		solve(v, ret, i + 1, s, size);
	}
}

vector<vector<int> > subsetsWithDup(vector<int> &S)  {
	sort(S.begin(), S.end());
	vector<vector<int> > ret;
	ret.push_back(S);
	if (S.empty())
	{
		return ret;
	}
	ret.push_back(vector<int>());
	int size = S.size();
	vector<int> tmp;
	if (size > 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (i < size - 1 && S[i] == S[i + 1])
			{
				continue;
			}
			tmp.push_back(S[i]);
			ret.push_back(tmp);
			tmp.clear();
		}
	}

	if (size >= 3)
	{
		tmp.clear();
		solve(tmp, ret, 0, S, size);
	}


	return ret;
}

int main()
{
	vector<int> v = { 0, 0, 1 };//{ 1, 2, 3, 4 };
	vector<vector<int> > ret = subsetsWithDup(v);
	ostream_iterator<int> ofile(cout, " ");
	int size = ret.size();
	for (int i = 0; i < size; i++)
	{
		copy(ret[i].begin(), ret[i].end(), ofile);
		cout << endl;
	}
	return 0;
}