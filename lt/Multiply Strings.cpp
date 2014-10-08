#include <iostream>
#include <string>

using namespace std;

string multiply(string num1, string num2)
{
	if (num1 == "0" || num2 == "0")
	{
		return "0";
	}
	
	int size1 = num1.size();
	int size2 = num2.size();
	int size = size1 + size2;
	string ret(size, '0');
	int c = 0;

	string tmp;
	string part;
	int index = 0;
	int num = 0;

	for (int i = size1 - 1; i >= 0; i--)
	{
		for (int j = size2 - 1; j >= 0; j--)
		{
			int tmp1 = ((num1[i] - '0') * (num2[j] - '0') + c);
			c = 0;
			if (tmp1 >= 10)
			{
				c = tmp1 / 10;
				tmp1 %= 10;
			}
			tmp .push_back(tmp1 + '0');
			num++;
		}
		if (c != 0)
		{
			tmp.push_back(c + '0');
			num++;
		}
		
		c = 0;
		int k, t;
		for (k = size - 1 - index, t = 0; k >= size - num, t < tmp.size(); k--, t++)
		{
			int tt = (ret[k] - '0') + (tmp[t] - '0') + c;
			c = 0;
			if (tt >= 10)
			{
				c = tt / 10;
				tt %= 10;
			} 
			ret[k] = tt + '0';
		}

		if (c != 0)
		{
			ret[k] = c + '0';
		}
		tmp.clear();
		num = 0;
		index++;
		c = 0;
	}

	index = 0;
	for (int i = 0; i < size; i++)
	{
		if (ret[i] != '0')
		{
			index = i;
			break;
		}
	}

	string ans(ret.begin() + index, ret.end());
	
	return ans;
}

int main()
{
	string s = "498828660196";
	string ss =  "840477629533";
	cout << multiply(s, ss) << endl;
	return 0;
}