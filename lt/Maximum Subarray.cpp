#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

/*
int maxSubArray(int A[], int n)
{
	int count = A[0];
	int max = A[0];
	for (int i = 1; i < n; i++)
	{		if (count < 0)
		{
			count = A[i];
		}
		else
		{
			count += A[i];
		}
		if (count > max)		{
			max = count;
		}
	}	return max;
}
*/


// int maxSubArray(int A[], int n) {
// 	int sum = A[0], max = A[0];
// 	for (int i = 1; i < n; i++) {
// 		sum = sum < 0 ? A[i] : sum + A[i];
// 		max = sum > max ? sum : max;
// 	}
// 	return max;
// 
// }

//TEL
//int ll = 0;
//int rr = 0;
int maxSum(int left, int right, int A[])
{
	if (left > right) return 0;

	if (left == right)
	{
		return A[left];
	}
	
	int mid = (left + right) / 2;

	int lMax = A[mid];
	int lSum = 0;
	for (int i = mid; i >= 0; i--)
	{
		lSum += A[i];
		if (lSum > lMax)
		{
			//ll = i;
			lMax = lSum;
		}
	}

	int rMax = A[mid + 1];
	int rSum = 0;
	for (int j = mid + 1; j < right; j++)
	{
		rSum += A[j];
		if (rSum > rSum)
		{
			//rr = j;
			rSum = rSum;
		}
	}

	return max(lMax + rMax, max(maxSum(left, mid, A), maxSum(mid + 1, right, A)));
}

int maxSubArray(int A[], int n)
{
	if (1 == n)
	{
		return A[0];
	}
	int max = 0;
	max = maxSum(0, n, A);
	return max;
}

int main()
{
	int a[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };//{ -2, -1, -3, -4, -10, -20, -10, -5, -4 };//{-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int max = maxSubArray(a, 9);
	//cout << "the start index :" << ll << endl;
	//cout << "the end index: " << rr << endl;
	cout << max << endl;
	return 0;
}