#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

vector<string> ret;
map<char, vector<char> > dict;


void dfs(int cur, int size, string &digits, string &ans)
{
	if (cur == size)
	{
		ret.push_back(ans);
		return;
	}
	int len = dict[digits[cur]].size();
	for (int i = 0; i < len; i++)
	{
		dfs(cur + 1, size, digits, ans + dict[digits[cur]][i]);
	}
}

vector<string> letterCombinations(string digits)
{
	string ans;
	ans.clear();
	dict.clear();
		
	dict['2'].push_back('a');
	dict['2'].push_back('b');
	dict['2'].push_back('c');
	dict['3'].push_back('d');
	dict['3'].push_back('e');
	dict['3'].push_back('f');
	dict['4'].push_back('g');
	dict['4'].push_back('h');
	dict['4'].push_back('i');
	dict['5'].push_back('j');
	dict['5'].push_back('k');
	dict['5'].push_back('l');
	dict['6'].push_back('m');
	dict['6'].push_back('n');
	dict['6'].push_back('o');
	dict['7'].push_back('p');
	dict['7'].push_back('q');
	dict['7'].push_back('r');
	dict['7'].push_back('s');
	dict['8'].push_back('t');
	dict['8'].push_back('u');
	dict['8'].push_back('v');
	dict['9'].push_back('w');
	dict['9'].push_back('x');
	dict['9'].push_back('y');
	dict['9'].push_back('z');

	dfs(0, digits.size(), digits, ans);

	return ret;
}

int main()
{
	vector<string> v;
	v = letterCombinations("23");
	int len = v.size();
	for (int i = 0; i < len; i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}