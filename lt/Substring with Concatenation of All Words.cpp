#include <iostream>
#include<vector>
#include<string>
#include <map>

using namespace std;


vector<int> findSubstring(string S, vector<string> &L)
{
	int size = L.size();
	vector<int> ret;
	string str = "";
	int wordSize = L[0].size();
	int sLen = S.size();
	map<string, int> wordCount;
	int i, j;

	if (size <= 0)
	{
		return vector<int>();
	}
	

	for ( i = 0; i < size; i++)
	{
		wordCount[L[i]]++;
	}
	
	map<string, int> countMp;
	for (i = 0; i < sLen - size * wordSize; i++)
	{
		countMp.clear();

		for (j = 0; j < size; j++)
		{
			str = S.substr(i + j * wordSize, wordSize);

			if (wordCount.find(str) != wordCount.end())
			{
				countMp[str]++;

				if (countMp[str] > wordCount[str])
				{
					break;
				}
				
			}
			else
			{
				break;
			}
		}
		
		if (j == size)
		{
			ret.push_back(i);
		}
		
	}
	return ret;
}

int main()
{
	vector<int> ans;
	string s = "barfoothefoobarman";
	vector<string> L = { "foo", "bar"};
	ans = findSubstring(s, L);
	int size = ans.size();

	for (int i = 0; i < size; i++)
	{
		cout << ans[i] << endl;
	}
	
	return 0;
}