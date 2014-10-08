#include <iostream>
#include <map>

using namespace std;

/*
int singleNumber(int A[], int n)
{
	map<int, int> m;

	for (int i = 0; i < n; i++)
	{
		m[A[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (1 == m[A[i]])
		{
			return A[i];
		}

	}

	return 0;
}
*/

int singleNumber(int A[], int n)
{
	int result;

	if (0 == n)
	{
		return 0;
	}

	result = A[0];
	for (int i = 1; i < n; i++)
	{
		result ^= A[i];
	}

	return result;
}

int main()
{
	int a[] = { 1, 2, 1, 4, 4, 6, 6, 3, 2 };
	int ans = singleNumber(a, 9);
	cout << ans << endl;
	return 0;
}