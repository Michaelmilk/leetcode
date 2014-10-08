#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void solve(int idx, int size, string buf, string digits, vector<string> &ans, map<char, vector<char> > &mp)
{
	if (idx == size)
	{
		ans.push_back(buf);
		return;
	}

	int s = mp[digits[idx]].size();
	for (int i = 0; i < s; i++)
	{
		buf.push_back(mp[digits[idx]][i]);
		solve(idx + 1, size, buf, digits, ans, mp);
		buf.pop_back();
	}
}

vector<string> letterCombinations(string digits)
{
	vector<string> ans;
	map<char, vector<char> > mp;
	mp['2'].push_back('a');
	mp['2'].push_back('b');
	mp['2'].push_back('c');
	mp['3'].push_back('d');
	mp['3'].push_back('e');
	mp['3'].push_back('f');
	mp['4'].push_back('g');
	mp['4'].push_back('h');
	mp['4'].push_back('i');
	mp['5'].push_back('j');
	mp['5'].push_back('k');
	mp['5'].push_back('l');
	mp['6'].push_back('m');
	mp['6'].push_back('n');
	mp['6'].push_back('o');
	mp['7'].push_back('p');
	mp['7'].push_back('q');
	mp['7'].push_back('r');
	mp['7'].push_back('s');
	mp['8'].push_back('t');
	mp['8'].push_back('u');
	mp['8'].push_back('v');
	mp['9'].push_back('w');
	mp['9'].push_back('x');
	mp['9'].push_back('y');
	mp['9'].push_back('z');

	int size = digits.length();
	solve(0, size, "", digits, ans, mp);
	return ans;
}

int main()
{
	/*
	vector<char> v;
	v.push_back('a');
	v.push_back('b');
	v.push_back('c');
	map<char, vector<char> > mp;
	mp['1'] = v;
	v.clear();
	v.push_back('z');
	v.push_back('x');
	v.push_back('c');
	mp['2'] = v;
	v.clear();

	cout << mp['1'][1] << endl;
	cout << mp['2'][1] << endl;
	*/

	vector<string> ans = letterCombinations("23");

	int size = ans.size();
	for (int i = 0; i < size; i++)
	{
		copy(ans[i].begin(), ans[i].end(), ostream_iterator<char>(cout, " "));
		cout << endl;
	}
	return 0;
	
	return 0;
}