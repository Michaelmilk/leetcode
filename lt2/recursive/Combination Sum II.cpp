#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


/*
int countTotal(vector<int> &buf)
{
	int size = buf.size();
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		count += buf[i];
	}
	return count;
}

void solve(int idx, int size, int target, vector<int> &buf, vector<int> &candidates, vector<vector<int> > &ans)
{
	int count = countTotal(buf);
	if (count >= target)
	{
		if (count == target)
		{
			ans.push_back(buf);
		}
		return;
	}

	for (int i = idx; i < size; i++)
	{
		buf.push_back(candidates[i]);
		solve(i + 1, size, target, buf, candidates, ans);
		buf.pop_back();
		while (i < size - 1 && candidates[i] == candidates[i + 1])//去除重复的子集
		{
			i++;
		}
	}
}

vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
{
	int size = candidates.size();
	vector<vector<int> > ans;
	if (0 == size)
	{
		return ans;
	}

	sort(candidates.begin(), candidates.end());

	vector<int> buf;
	solve(0, size, target, buf, candidates, ans);

	return ans;
}
*/
//通过target减去相应的值，来优化算法
void dfs(vector<int> &num, int target, vector<int> &temp, vector<vector<int> > &rst, int pos)
{
	if (target < 0)
		return;
	if (target == 0)
	{
		rst.push_back(temp);
		return;
	}

	for (int i = pos; i < num.size(); i++)
	{
		temp.push_back(num[i]);
		dfs(num, target - num[i], temp, rst, i + 1);
		temp.pop_back();
		while (i < num.size() - 1 && num[i] == num[i + 1])//nice idea除去重复的子集，相同值中去最后一个值
			i++;
	}
}

vector<vector<int> > combinationSum2(vector<int> &num, int target)
{
	vector<int> temp;
	vector<vector<int> > rst;
	sort(num.begin(), num.end());
	dfs(num, target, temp, rst, 0);
	return rst;
}


int  main()
{
	vector<int> v = { 10, 1, 2, 7, 6, 1, 5};
	vector<vector<int> > ans = combinationSum2(v, 8);

	int size = ans.size();
	for (int i = 0; i < size; i++)
	{
		copy(ans[i].begin(), ans[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}