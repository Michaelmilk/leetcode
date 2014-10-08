#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

/*
int trap(int A[], int n)
{
	if (n < 3)
	{
		return 0;
	}

	int max = 0;
	int maxIdx;
	int leftMax = A[0];
	int rightMax = A[n - 1];
	int waterCount = 0;

	for (int i = 0; i < n; i++)
	{
		if (max < A[i])
		{
			max = A[i];
			maxIdx = i;
		}
	}


	for (int i = 1; i < maxIdx; i++)
	{
		if (A[i] > leftMax)
		{
			leftMax = A[i];
		}
		else
		{
			waterCount += leftMax - A[i]; 
		}
	}

	for (int i = n - 2; i > maxIdx; i--)
	{
		if (A[i] > rightMax)
		{
			rightMax = A[i];
		}
		else
		{
			waterCount += rightMax - A[i];
		}
	}

	return waterCount;
}
*/

int trap(int A[], int n)
{
	if (n < 3)
	{
		return 0;
	}

	vector<int> left(n, 0);
	vector<int> right(n, 0);
	int waterCount = 0;

	left[0] = 0; 
	for (int i = 1; i < n; i++)
	{
		left[i] = A[i - 1] > left[i - 1] ? A[i - 1] : left[i - 1];
	}

	right[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		right[i] = A[i + 1] > right[i + 1] ? A[i + 1] : right[i + 1];
	}

	for (int i = 1; i < n - 1; i++)
	{
		int high = (min(left[i], right[i]) - A[i]);
		if (0 < high)
		{
			waterCount += high;
		}
	}

	return waterCount;
}

int main()
{
	int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int ans = trap(a, 12);
	cout << ans << endl;
	return 0;
}