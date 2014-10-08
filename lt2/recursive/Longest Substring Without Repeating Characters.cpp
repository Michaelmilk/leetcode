#include <iostream>
#include <string>
#include <vector>

using namespace std;
int st = -1;
int e = -1;

int lengthOfLongestSubstring(string s)
{
	vector<int> hash(125, -1);
	int sp = -1;
	int len = s.length();
	int max = 0;

	for (int i = 0; i < len; i++)
	{
		if (hash[s[i]] != sp)
		{
			sp = hash[s[i]];
		}

		//���������ظ���ĸ֮�������ظ��Ӵ��ĳ���
		//max = max > i - sp ? max : i - sp;
		if (max < i - sp)
		{
			max = i - sp;
			st = sp + 1;
			e = i;
		}

		hash[s[i]] = i;
	} 

	return max;
}

int main()
{
	string s = "abcabcbb";
	cout << lengthOfLongestSubstring(s) << endl;
	cout << s.substr(st, e + 1) << endl;
	return 0;
}