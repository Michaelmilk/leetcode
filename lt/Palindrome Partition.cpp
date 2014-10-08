#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> ans;

bool isPalindrome(string s)
{
	int len = s.length();
	/*for (int i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - 1 - i])
		{
			return false;
		}
	}*/
	int l = 0;
	len = len - 1;
	while (l < len)
	{
		if (s[l++] != s[len--])
		{
			return false;
		}
	}
	return true;
}

//TLE
//void partitionSolve(int idx, vector<string> t, string s, int len)
//{
//	if (idx == len)
//	{
//		ans.push_back(t);
//		return;
//	}
//
//	for (int i = idx; i < len; i++)
//	{
//		vector<string> vStr(t);
//		string tmp(s.begin() + idx, s.begin() + i + 1);
//		//string tmp = s.substr(0, i + 1);
//		if (isPalindrome(tmp))
//		{
//			vStr.push_back(tmp);
//			partitionSolve(i + 1, vStr, s, len);
//		}
//	}
//}

void partitionSolve(int idx, vector<string> t, string s, int len)
{
	if (idx == len)
	{
		ans.push_back(t);
		return;
	}

	vector<string> vStr(t);//ºÄÊ±£¿£¿£¿
	for (int i = idx; i < len; i++)
	{
		
		string tmp(s.begin() + idx, s.begin() + i + 1);
		//string tmp = s.substr(0, i + 1);
		if (isPalindrome(tmp))
		{
			vStr.push_back(tmp);
			partitionSolve(i + 1, vStr, s, len);
			vStr.pop_back();
		}
	}
}

vector<vector<string>> partition(string s)
{
	if (s.empty())
	{
		return ans;
	}

	int len = s.length();
	vector<string> t;
	partitionSolve(0, t, s, len);

	return ans;
}

int main()
{
	vector<vector<string>> v;
	v = partition("aab");

	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		copy(v[i].begin(), v[i].end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}
	return 0;
}