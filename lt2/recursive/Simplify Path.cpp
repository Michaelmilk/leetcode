#include <iostream>
#include <vector>
#include <string>

using namespace std;

string simplifyPath(string path)
{
	string ans = "";
	vector<string> buf;
	int len = path.length();
	int idx = 0;

	while (idx < len)
	{
		int end = idx + 1;
		while (end < len && path[end] != '/')
		{
			end++;
		}
		string str = path.substr(idx + 1, end - idx - 1);
		if (!str.empty())
		{
			if (str == "..")
			{
				if (!buf.empty())
				{
					buf.pop_back();
				}
			}
			else if (str != ".")
			{
				buf.push_back(str);
			}
		}
		idx = end;
	}

	int size = buf.size();
	if (0 == size)
	{
		return "/";
	}

	for (int i = 0; i < size; i++)
	{
		ans += "/" + buf[i];
	}

	return ans;
}

int main()
{
	cout << simplifyPath("/a/./b/../../c/") << endl;
	return 0;
}