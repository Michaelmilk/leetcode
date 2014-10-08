#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
	vector<int> ret;
	int c = 0;
	int size = digits.size();
	int tmp = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		
		if (i == size - 1)
		{
			tmp = digits[size - 1] + 1;
		}
		else
		{
			tmp = digits[i] + c;
		}
		c = 0;
		if (tmp >= 10)
		{
			digits[i] = tmp % 10;
			c = 1;
		}
		else
		{
			digits[i] = tmp;
		}
		ret.push_back(digits[i]);
	}
	if (c != 0)
	{
		ret.push_back(c);
	}

	vector<int> ans(ret.rbegin(), ret.rend());
	return ans;
}

