#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
vector<vector<int> > ret;

void solve(int dep, int maxDep, int target, vector<int> &can)
{
	if (target < 0)
	{
		return;
	}

	if (dep == maxDep)
	{
		if (target == 0)
		{
			vector<int> res;
			for (int i = 0; i < maxDep; i++)
			{
				for (int j = 0; j < num[i]; j++)
				{
					res.push_back(can[i]);
				}
				
			}
			ret.push_back(res);
		}
		return;
	}
	
	for (int i = 0; i <= target / can[dep]; i++)
	{
		num[dep] = i;
		solve(dep + 1, maxDep, target - can[dep] * i, can);
	}	
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
	sort(candidates.begin(), candidates.end());

	int size = candidates.size();
	ret.clear();
	num.resize(size);

	if (0 == size)
	{
		return ret;
	}
	
	solve(0, size, target, candidates);

	return ret;
}

int main()
{
	vector<int> v = {1, 2, 3, 4, 5, 6, 8};
	vector<vector<int> > r;

	r = combinationSum(v, 8);

	int size = r.size();

	for (int i = 0; i < size; i++)
	{
		int tmpSize = r[i].size();
		for (int j = 0; j < tmpSize; j++)
		{
			cout << r[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}