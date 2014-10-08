#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

//TLE原因主要是isPalindrome重复调用，每次已经比较过的次啊一次还是要比较！
//bool isPalindrome(string s, int l, int r, vector<vector<bool> > v)
//{
//	int left = l;
//	int right = r;
//	if (v[l][r])
//	{
//		return true;
//	} 
//	else
//	{
//		while (l < r)
//		{
//			if (s[l] != s[r])
//			{
//				return false;
//			}
//			l++;
//			r--;
//		}
//	}
//	
//	v[left][right] = true;
//	return true;
//}
//
//int minCut(string s)
//{
//	int len = s.length();
//	vector<vector<bool> > v(len, vector<bool>(len, false));
//	vector<vector<int> > table(len);
//
//	for (int i = len - 1; i >= 0; i--)
//	{
//		if (isPalindrome(s, i, len - 1, v))
//		{
//			table[i].push_back(len - 1);
//		}
//	}
//
//	for (int i = len - 2; i >= 0; i--)
//	{
//		if (!table[i + 1].empty())
//		{
//			for (int j = i, d = 0; j >= 0; j--, d++)
//			{
//				if (v[j][j + d] || isPalindrome(s, j, j + d, v))
//				{
//					table[j].push_back(i);
//				}
//			}
//		}
//	}
//
//	int ans = 0;
//	int idx = 0;
//	while (true)
//	{
//		if (table[idx].front() == len - 1)
//		{
//			break;
//		}
//		idx = table[idx].front() + 1;
//		ans++;
//	}
//
//	return ans;
//}


/*res[i] 区间[i,n]之间最少的回文数（最小的cut数=最少的回文数-1），n为字符串长度，
则res[i] = min(1+res[j+1], res[i] )    i<=j <n.([i,j]是回文，[j+1,n]是回文)
即取原先的res[i]与res[j + 1]+1的最小值，因为{i，j]和j+1,n]已经是回文了，
所以只要在res[j + 1]的基础上再加1，就是当前的res[i]
有个转移函数之后，一个问题出现了，就是如何判断[i,j]是否是回文？
每次都从i到j比较一遍？太浪费了，这里也是一个DP问题。
定义函数
P[i][j] = true if [i,j]为回文
那么
P[i][j] = (str[i] == str[j] && P[i+1][j-1]);
*/

//从后往前统计
//int minCut(string s) 
//{
//	// Start typing your C/C++ solution below
//	// DO NOT write int main() function
//	int n = s.size();
//	vector<int > res(n + 1);
//	vector<vector<bool> > p(n, vector<bool>(n, false));
//	for (int i = 0; i <= n; ++i)//最坏的情况每个字符为一个回文
//	{
//		res[i] = n - i;
//	}
//	for (int i = n - 1; i >= 0; --i)
//	{
//		for (int j = i; j < n; ++j)
//		{
//			//判断[i, j]是回文（先判断s[i]==s[j]再判断[i+1,j-1]是不是回文）
//			if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
//			{
//				p[i][j] = true;
//				res[i] = min(res[i], res[j + 1] + 1);
//			}
//		}
//	}
//	return res[0] - 1;
//}


/*res[i] 区间[0,i]之间最小的cut数（最小的cut数=最少的回文数-1），n为字符串长度，
定义函数
P[i][j] = true if [i,j]为回文
那么
P[i][j] = (str[i] == str[j] && P[i+1][j-1]);
*/

//从前往后统计
int minCut(string s)
{
	int len = s.length();
	vector<int> ans(len + 1);
	vector<vector<bool> > dp(len, vector<bool>(len, false));

	//for (int i = 0; i <= len; i++)
	//{
	//	ans[i] = i - 1;
	//}

	//for (int i = 0; i < len; i++)
	//{
	//	for (int j = 0; j <= i; j++)
	//	{
	//		if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]))
	//		{
	//			dp[j][i] = true;
	//			ans[i + 1] = min(ans[i + 1], ans[j] + 1);//ans[i] = min(ans[i], ans[j - 1] + 1);当j=0时出界
	//		}
	//	}
	//}
	//return ans[len];

	for (int i = 0; i < len; i++)
	{
		ans[i] = i;
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]))
			{
				dp[j][i] = true;
				ans[i] = j != 0 ? min(ans[i], ans[j - 1] + 1) : ans[0];//ans[i] = min(ans[i], ans[j - 1] + 1);当j=0时出界
			}
		}
	}
	return ans[len - 1];
}
int main()
{
	//vector<vector<string>> v;
	int ans = minCut("aab");
	cout << ans << endl;

	/*int size = v.size();
	for (int i = 0; i < size; i++)
	{
		copy(v[i].begin(), v[i].end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}*/
	return 0;
}