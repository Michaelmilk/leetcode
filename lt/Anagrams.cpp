#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> anagrams(vector<string> &strs)
{
	vector<string> ret;
	string str;
	map<string, int> mp;
	int size = strs.size();

	for (int i = 0; i < size; i++)
	{
		str = strs[i];
		sort(str.begin(), str.end());

		if (mp.find(str) == mp.end())
		{
			mp[str] = i;
		}
		else
		{
			if (mp[str] >= 0)//第一次添加某个字符串一样字符组成的字符串
			{
				ret.push_back(strs[mp[str]]);
				mp[str] = -1;
			}
			ret.push_back(strs[i]);
		}
	}
	return ret;
}