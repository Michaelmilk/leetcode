#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseWords(string &s)
{
	vector<string> v;
	int len = s.length();
	int start = 0;
	while (s[start] == ' ' && start < len)//除去前置空格
	{
		start++;
	}

	int end = len - 1;
	while (s[end] == ' ' && end >= 0)//除去前置空格
	{
		end--;
	}
	int idx = start;
	s += ' ';
	for (int i = start; i <= end + 1; i++)
	{
		if (s[i] == ' ')
		{
			string str = s.substr(idx, i - idx);
			v.push_back(str);
			while (s[i + 1] == ' ')
			{
				i++;
			}
			idx = i + 1;
		}
	}

	s.clear();
	int size = v.size();
	for (int i = size - 1; i >= 0; i--)
	{
		s += i == 0 ? v[i] : v[i] + ' ';
	}
}

int main()
{
	string s = "  the s  ky is    blue   ";
	reverseWords(s);
	cout << s << endl;
}
