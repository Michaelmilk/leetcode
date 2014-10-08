#include <iostream>
#include <algorithm>

using namespace std;

int trap(int A[], int n)
{
	if (0 == n)
	{
		return 0;
	}
	
	int ret = 0;;
	int max;
	int *left = new int[n];
	int *right = new int[n];

	left[0] = A[0];
	max = A[0];
	for (int i = 1; i < n; i++)
	{
		if (A[i] < max)
		{
			left[i] = max;
		} 
		else
		{
			max = A[i];
			left[i] = max;
		}
	}


	right[n - 1] = A[n - 1];
	max = A[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (A[i] < max)
		{
			right[i] = max;
		} 
		else
		{
			max = A[i];
			right[i] = max;
		}
	}

	for (int i = 1; i < n;i++)
	{
		int trap = (min(left[i], right[i]) - A[i]) * 1;
		if (trap > 0)
		{
			ret += trap;
		}
	}

	return ret;
}

int main()
{
	int a[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	cout << trap(a, 12) << endl;
	return 0;
}