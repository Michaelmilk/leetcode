#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
double findMedianSortedArrays(int A[], int m, int B[], int n) 
{
	int *a = new int[m + n];

	memcpy(a, A, sizeof(int)*m);
	memcpy(a + m, B, sizeof(int)*n);

	sort(a, a + n + m);

	double median = (double)((n + m) % 2 ? a[(n + m) >> 1] : (a[(n + m - 1) >> 1] + a[(n + m) >> 1]) / 2.0);

	delete a;

	return median;


}*/

double findMedian(int A[], int m, int B[], int n, int k)
{
	if (m > n)
	{
		return findMedian(B, n, A, m, k);
	}

	if (0 == m)
	{
		return B[k - 1];
	}

	if (1 == k)
	{
		return min(A[0], B[0]);
	}

	int pa = min(k / 2, m);
	int pb = k - pa;

	if (A[pa - 1] < B[pb - 1])
	{
		return findMedian(A + pa, m - pa, B, n, k - pa);
	}
    else if (A[pa - 1] > B[pb - 1])
	{
		return findMedian(A, m, B + pb, n - pb, k - pb);
	}
	else
	{
		return A[pa - 1];
	}
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	int len = m + n;

	if (len & 0x1)
	{
		return findMedian(A, m, B, n, len / 2 + 1);
	}
	else
	{
		return (findMedian(A, m, B, n, len / 2) + findMedian(A, m, B, n, len / 2 + 1)) / 2;
	}
}


int main()
{
	int a[2] = {1, 2};
	int b[2] = {4, 9};
	cout << findMedianSortedArrays(a, 2, b, 2) << endl;
	return 0;
}