#include <iostream>
#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path)
{
	int len = path.length();
	if (0 == len)
	{
		return "";
	}
	path += "/";
	len += 1;
	string ret;
	vector <string> v;
	v.push_back("/");
	int start = 1;

	for (int i = start; i < len; i++)
	{
		if ('/' == path[i] && i == start)
		{
			start++;
			//i = start - 1;
			continue;
		}

		if ('/' == path[i])
		{
			string tmp = path.substr(start, i - start);
			v.push_back(tmp);
			start = i + 1;
			//i = start - 1;
		}
	}

	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		cout << v[i] << endl;
	}
	cout << "---------------" << endl;

	for (vector<string>::iterator it = v.begin(); it != v.end();)
	{
		if ("." == *it)
		{
			v.erase(it);
			continue;
		}
		if (".." == *it)
		{
			if ("/" == *(it - 1))
			{
				v.erase(it);
				continue;
			}
			else
			{
				it = v.erase(it - 1, it + 1);
				continue;
			}
		}
		it++;
	}

	size = v.size();
	for (int i = 0; i < size; i++)
	{
		cout << v[i] << endl;
	}

	
	ret = "/";
	for (int i = 1; i < size; i++)
	{
		if (i != size - 1)
		{
			ret += v[i] + "/";
		}
		else
		{
			ret += v[i];
		}
	}
	return ret;
}

int main()
{
	//cout << simplifyPath("//abc/g//c//../..//s") << endl;
	cout << simplifyPath("/.") << endl;
	return  0;
}