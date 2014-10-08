#include<iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
	int len = s.length();
	//map<char, int> pos;
	int hash[125];
	int max = 0;
	int sp = -1;

	memset(hash, -1, 125 * sizeof(int));//memset is Byte assignment

	for (int i = 0; i < len; i++)
	{
		if (hash[s[i]] > sp)
		{
			sp = hash[s[i]];
		}

		if (i - sp > max)
		{
			max = i - sp;
		}

		hash[s[i]] = i;
	}

	return max;
}

int main()
{
	string s = "abcadefgh";

	cout << lengthOfLongestSubstring(s) << endl;

	return 0;
}