#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > ret;
vector<int> v;

void solve(int cur, int n, int k, int start)
{
	if (cur == k)
	{
		ret.push_back(v);
		return;
	}
	else
	{
		for (int i = start; i <= n; i++)
		{
			int ok = 1;

			for (int j = 0; j < cur; j++)
			{
				if (v[j] == i)
				{
					ok = 0;
				}
			}

			if (ok)
			{
				v[cur] = i;
				solve(cur + 1, n, k, i + 1);
			}

		}
	}
}

vector<vector<int> > combine(int n, int k)
{
	v.resize(k);

	solve(0, n, k, 1);
	return ret;
}



/*
vector<vector<int> > ret;
vector<int> a;

void solve(int dep, int maxDep, int n, int start)
{
	if (dep == maxDep)
	{
		ret.push_back(a);
		return;
	}

	for (int i = start; i <= n; i++)
	{
		a[dep] = i;
		solve(dep + 1, maxDep, n, i + 1);
	}
}

vector<vector<int> > combine(int n, int k) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	a.resize(k);
	ret.clear();
	solve(0, k, n, 1);
	return ret;
}
*/

int main()
{
	vector<vector<int> > ans;
	ans = combine(4, 2);

	int size = ans.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
}