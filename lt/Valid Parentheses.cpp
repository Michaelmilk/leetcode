#include<iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s)
{
	int size = s.size();
	int ssize;

	stack<char> ss;

	for (int i = 0; i < size; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			ss.push(s[i]);
		}
		else if (s[i] == ')')
		{
			ssize = ss.size();
			if (!ssize)
			{
				return false;
			}

			char tmp = ss.top();
			
			if (tmp == '(')
			{
				ss.pop();
			}
			else
			{
				break;
			}
		}
		else if (s[i] == ']')
		{
			ssize = ss.size();
			if (!ssize)
			{
				return false;
			}
			char tmp = ss.top();
			
			if (tmp == '[')
			{
				ss.pop();
			}
			else
			{
				break;
			}
		}
		else if (s[i] == '}')
		{
			ssize = ss.size();
			if (!ssize)
			{
				return false;
			}
			char tmp = ss.top();
			if (tmp == '{')
			{
				ss.pop();
			}
			else
			{
				break;
			}
		}
	}

	ssize = ss.size();

	return ssize ? false : true;
	
}

int main()
{
	cout << isValid("(") << endl;
	
	return 0;
}