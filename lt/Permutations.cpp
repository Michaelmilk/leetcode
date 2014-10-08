#include <iostream>
#include <vector>
#include <iterator>

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
			int ok = 1;

			for (int j = 0; j < cur; j++)
			{
				if (v[j] == num[i])
				{
					ok = 0;
				}
			}

			if (ok)
			{
				v[cur] = num[i];
				solve(cur + 1, num, ret1, size);
			}
			
		}
	}
}

vector<vector<int> > permute(vector<int> &num)
{
	
	int size = num.size();
	v.resize(size);

	solve(0, num, ret, size);
	return ret;
}

int main()
{
	vector<int> v = {1, 2, 3};

	ostream_iterator<int> ofile(cout, " ");

	permute(v);

	for (int i = 0; i < ret.size(); i++)
	{
		copy(ret[i].begin(), ret[i].end(), ofile);
		cout << endl;
	}
	return 0;
}