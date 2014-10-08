#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/*//TLE
string ret;
int sum = 0;
string s;
void solve(int cur, int n, int k)
{
	if (!ret.empty())
	{
		return;
	}

	if (cur == n)
	{
		sum++;
		if (sum == k)
		{
			ret = s;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			int ok = 1;

			for (int j = 0; j < cur; j++)
			{
				if (s[j] == i + '0')
				{
					ok = 0;
				}
			}

			if (ok)
			{
				s[cur] = i + '0';
				solve(cur + 1, n, k);
			}

		}
	}
}*/
/*
string ret;
int sum = 0;
string s;
int p = 0;
void solve(int cur, int n, int k)
{
	int t = 1;
	sum = 0;
	for (int i = 1; i < p; i++)
	{
		t *= i;
	}
	int now = 0;
	if (1 != t)
	{
		
		if (k % t)
		{
			now = k / t + 1 + (n - p);
			k = k % t;
		}
		else
		{
			now = k / t;
			k = t;
		}
	}
	else
	{
		now = 1;
		k = 1;
	}

	if (!ret.empty())
	{
		return;
	}

	if (cur == n)
	{
		sum++;
		if (sum == k)
		{
			ret = s;
		}
	}
	else
	{
		for (int i = now; i <= n; i++)
		{
			int ok = 1;

			for (int j = 0; j < cur; j++)
			{
				if (s[j] == i + '0')
				{
					ok = 0;
				}
			}

			if (ok)
			{
				s[cur] = i + '0';
				p--;
				solve(cur + 1, n, k);
			}

		}
	}
}

string getPermutation(int n, int k) 
{
	s.resize(n);
	ret.clear();
	p = n;
// 	int t = 1;
// 	for (int i = 1; i < n; i++)
// 	{
// 		t *= i;
// 	}
// 
// 	int cur = 0;
// 	if (k % t)
// 	{
// 		cur = k / t + 1;
// 		k = k % t;
// 	}
// 	else
// 	{
// 		cur = k / t;
// 		k = t;
// 	}
// 	
	solve(0, n, k);

	return ret;
}*/

string ret;
int sum = 0;


string getPermutation(int n, int k)
{
	string s;
	s.resize(n);
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	
	int size = n;
	int cur = 0;
	while (cur < n)
	{
		int t = 1;
		for (int i = 1; i < size; i++)
		{
			t *= i;
		}
		int now = 0;
		
		if (k % t)
		{
			now = k / t + 1;
			k = k % t;
		}
		else
		{
			now = k / t;
			k = t;
		}
		s[cur++] = v[now - 1] + '0';
		v.erase(v.begin() + now - 1);
		size -= 1;
	}
	

	return s;
}

int main()
{
	cout << getPermutation(4, 7) << endl;
	return 0;
}