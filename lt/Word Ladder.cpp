#include <iostream>
#include <string>
#include <queue>
//#include <utility>
#include <unordered_set>

using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict) 
{
	int ans = 0;
	dict.insert(end);
	queue<pair<string, int> > que;
	que.push(pair<string, int>(start, 1));

	while (!que.empty())
	{
		pair<string, int> elemPair = que.front();
		que.pop();

		if (elemPair.first == end)
		{
			ans = elemPair.second;
			break;
		}

		string s = elemPair.first;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			for (char ch = 'a'; ch <= 'z'; ch++)
			{
				if (s[i] == ch)
				{
					continue;
				}
				char tmp = s[i];
				s[i] = ch;
				if (dict.find(s) != dict.end())
				{
					que.push(pair<string, int>(s, elemPair.second + 1));
					dict.erase(s);
				}
				s[i] = tmp;//回复原来的字符串，进行下一次检索，因为与该字串相差一个字符的字串可能不只一个
			}
		}
	}
	return ans;
}


/*
int main()
{
	std::unordered_set<std::string> myset =
	{ "USA", "Canada", "France", "UK", "Japan", "Germany", "Italy" };

	//myset.erase(myset.begin());                    // erasing by iterator
	myset.erase("France");                         // erasing by key
	myset.erase(myset.find("Japan"), myset.end()); // erasing by range

	std::cout << "myset contains:";
	//for (const std::string& x : myset) std::cout << " " << x;
	for (unordered_set<string>::iterator it = myset.begin(); it != myset.end(); it++)
	{
		cout << *it << endl;
	}
	//std::cout << std::endl;

	return 0;
}
*/
