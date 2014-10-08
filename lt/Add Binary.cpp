#include <iostream>
#include <vector>
#include <string>

using namespace std;


string addBinary(string a, string b)
{
	string ans;
	bool flag = false;;
	int size1 = a.length();
	int size2 = b.length();
	if (size1 < size2)
	{
		int t = size1;
		size1 = size2;
		size2 = t;
		flag = true;
	}
	

	int c = 0;
	int tmp = 0;

	for (int i = size1 - 1, j = size2 - 1; i >= 0 || j >= 0; i--, j--)
	{
		if (flag)
		{
			if (j >= 0)
			{
				tmp = a[j] - '0' + b[i] - '0' + c;
			}
			else
			{
				tmp = b[i] - '0' + c;
			}
		} 
		else
		{
			if (j >= 0)
			{
				tmp = a[i] - '0' + b[j] - '0' + c;
			}
			else
			{
				tmp = a[i] - '0' + c;
			}
		}	
		c = 0;
		if (tmp >= 2)
		{
			c = 1;
			tmp = tmp % 2;
		}
		ans += tmp + '0';
	}
	
	if (c != 0)
	{
		ans += c + '0';
	}

	string ret(ans.rbegin(), ans.rend());
	return ret;
}

int main()
{
	cout << addBinary("1111", "1111") << endl;
}