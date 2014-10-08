#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int> > ret;
vector<int> a;

void solve(int dep, int maxDep, vector<int> &num, int target)
{
	if (target < 0)
		return;

	if (dep == maxDep)
	{
		if (target == 0)
		{
			vector<int> res;
			for (int i = 0; i < maxDep; i++)
			for (int j = 0; j < a[i]; j++)
				res.push_back(num[i]);
			ret.push_back(res);
		}

		return;
	}

	for (int i = 0; i <= min(target / num[dep], 1); i++)
	{
		a[dep] = i;

		//相当于首先只使用相同数字中的后面一个，如果前面的相同的数值被选中的话，后面的相同数字才能被选中
		if (i == 1 && dep > 0 && num[dep - 1] == num[dep] && a[dep - 1] == 0)
			continue;

		solve(dep + 1, maxDep, num, target - i * num[dep]);
	}
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	sort(num.begin(), num.end());
	a.resize(num.size());
	ret.clear();
	if (num.size() == 0)
		return ret;

	solve(0, num.size(), num, target);

	/*sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());*/

	return ret;
}


int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 8, 1, 1};
	vector<vector<int> > r;

	r = combinationSum2(v, 8);

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