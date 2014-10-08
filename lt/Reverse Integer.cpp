#include<iostream>
#include <vector>

using namespace std;

__int64 reverse(int x)
{
	int base = 10;
	int u = 0;
	int n = x;
	bool c = false;
	vector<int> v;
	//long long ret = 0;
	__int64 ret = 0;

	if (n < 0)
	{
		c = true;
		n = 0 - n;
	}

	while (n)
	{
		u = n % base;
		v.push_back(u);
		n = n / base;
	}

	int size = v.size();
	bool st = false;

	for (int i = 0; i < size; i++)
	{
		if (v[i])
		{
			st = true;
		}

		if (st)
		{
			ret *= base;
			ret += v[i];
		}
	}

	if (c)
	{
		return (-1 * ret);
	}
	return ret;
}

int main()
{
	int a = 2000000005;
	cout << reverse(a) << endl;
	return 0;
}