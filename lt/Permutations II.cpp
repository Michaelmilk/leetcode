#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


vector<vector<int> > ret;
vector<int> v;

void solve(int cur, vector<int> &num, vector<vector<int> >&ret1, int size)
{
	if (cur == size)
	{
		ret1.push_back(v);
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (!i || num[i] != num[i - 1])
			{
				int c1 = 0;;
				int c2 = 0;
				for (int j = 0; j < cur; j++)
				{
					if (num[i] == v[j])
					{
						c1++;
					}
				}

				for (int t = 0; t < size; t++)
				{
					if (num[i] == num[t])
					{
						c2++;
					}
				}

				if (c1 < c2)
				{
					v[cur] = num[i];
					solve(cur + 1, num, ret1, size);
				}
			}

		}
	}
}

vector<vector<int> > permuteUnique(vector<int> &num)
{

	int size = num.size();
	v.resize(size);

	solve(0, num, ret, size);
	return ret;
}/*
vector<vector<int> > ret;
vector<int> v;void solve(vector<int> &num){	int size = num.size();	if (0 == size)
	{
		ret.push_back(v);
	}	for (int i = 0; i < size; i++)
	{
		if (i + 1 < size && num[i] == num[i + 1])//如果开始的数字有重复，就可以使得开始的数值为重复数值中的最后一个
		{
			continue;
		}

		vector<int> tmp = num;
		v.push_back(num[i]);

		for (int j = i; j < size - 1; j++)
		{
			tmp[j] = tmp[j + 1];
		}

		tmp.pop_back();
		solve(tmp);
		v.pop_back();
	}}vector<vector<int> > permuteUnique(vector<int> &num)
{
	sort(num.begin(), num.end());

	solve(num);

	return ret;
}*/

int main()
{
	vector<int> v = {1, 3, 4};

	ostream_iterator<int> ofile(cout, " ");

	permuteUnique(v);

	for (int i = 0; i < ret.size(); i++)
	{
		copy(ret[i].begin(), ret[i].end(), ofile);
		cout << endl;
	}

	return 0;
}