#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
	int size = strs.size();
	if (!size)
	{
		return "";
	}
	
	int count = strs[0].size();//因为如果只有一个字符串，那么就可以输出整个字符串
	int j = 0;
	for (int i = 1; i < size; i++)
	{
		int len = strs[i].size();
		for (j = 0; j < len; j++)
		{
			if (j > len || strs[0][j] != strs[i][j])
			{
				break;
			}
			
		}
		count = count > j ? j : count;//该语句不能放还在for中，否则如果全部匹配，且比strs[0]短，那么就会输出strs[0]
	}	

	return strs[0].substr(0, count);
}

int main()
{
	vector<string> s;
	s.push_back("aadfgfgh");
	s.push_back("aadfgfgh");
	s.push_back("aswfet");
	s.push_back("attrytrooiuiu");
	s.push_back("apppe");

	cout << longestCommonPrefix(s) << endl;
	return 0;
}