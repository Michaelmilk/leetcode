#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
	int n = x;

	if (n < 0)
	{
		return false;
	}

	int len;
	__int64 base = 1;

	for (int i = 1; i <= 12; i ++)
	{
		int k = n % base;
		if (n == n % base)
		{
			len = i - 1;
			break;
		}
		base *= 10;
	}

	int mid =len / 2;
	int p = 0;

	while (mid--)
	{
		p = p * 10 + n % 10;
		n /= 10;
	}
	
	n = len % 2 ? n / 10 : n;//如果长度是奇数，那么你的最后一位要除去

	if (n == p)
	{
		return true;
	}

	return false;
}

int main()
{
	int n = 1410110141;
	cout << isPalindrome(n) << endl;
	return 0;
}