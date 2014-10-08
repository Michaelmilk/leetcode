#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

//TLEԭ����Ҫ��isPalindrome�ظ����ã�ÿ���Ѿ��ȽϹ��Ĵΰ�һ�λ���Ҫ�Ƚϣ�
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


/*res[i] ����[i,n]֮�����ٵĻ���������С��cut��=���ٵĻ�����-1����nΪ�ַ������ȣ�
��res[i] = min(1+res[j+1], res[i] )    i<=j <n.([i,j]�ǻ��ģ�[j+1,n]�ǻ���)
��ȡԭ�ȵ�res[i]��res[j + 1]+1����Сֵ����Ϊ{i��j]��j+1,n]�Ѿ��ǻ����ˣ�
����ֻҪ��res[j + 1]�Ļ������ټ�1�����ǵ�ǰ��res[i]
�и�ת�ƺ���֮��һ����������ˣ���������ж�[i,j]�Ƿ��ǻ��ģ�
ÿ�ζ���i��j�Ƚ�һ�飿̫�˷��ˣ�����Ҳ��һ��DP���⡣
���庯��
P[i][j] = true if [i,j]Ϊ����
��ô
P[i][j] = (str[i] == str[j] && P[i+1][j-1]);
*/

//�Ӻ���ǰͳ��
//int minCut(string s) 
//{
//	// Start typing your C/C++ solution below
//	// DO NOT write int main() function
//	int n = s.size();
//	vector<int > res(n + 1);
//	vector<vector<bool> > p(n, vector<bool>(n, false));
//	for (int i = 0; i <= n; ++i)//������ÿ���ַ�Ϊһ������
//	{
//		res[i] = n - i;
//	}
//	for (int i = n - 1; i >= 0; --i)
//	{
//		for (int j = i; j < n; ++j)
//		{
//			//�ж�[i, j]�ǻ��ģ����ж�s[i]==s[j]���ж�[i+1,j-1]�ǲ��ǻ��ģ�
//			if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
//			{
//				p[i][j] = true;
//				res[i] = min(res[i], res[j + 1] + 1);
//			}
//		}
//	}
//	return res[0] - 1;
//}


/*res[i] ����[0,i]֮����С��cut������С��cut��=���ٵĻ�����-1����nΪ�ַ������ȣ�
���庯��
P[i][j] = true if [i,j]Ϊ����
��ô
P[i][j] = (str[i] == str[j] && P[i+1][j-1]);
*/

//��ǰ����ͳ��
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
	//			ans[i + 1] = min(ans[i + 1], ans[j] + 1);//ans[i] = min(ans[i], ans[j - 1] + 1);��j=0ʱ����
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
				ans[i] = j != 0 ? min(ans[i], ans[j - 1] + 1) : ans[0];//ans[i] = min(ans[i], ans[j - 1] + 1);��j=0ʱ����
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