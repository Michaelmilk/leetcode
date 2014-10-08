#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

int maxProduct(int A[], int n)
{
	int ans = 0;
	vector<int> maxV(n, 0);
	vector<int> minV(n, 0);

	maxV[0] = minV[0] = A[0];

	for (int i = 1; i < n; i++)
	{
		maxV[i] = max(A[i], max(maxV[i - 1] * A[i], minV[i - 1] * A[i]));
		minV[i] = min(A[i], min(maxV[i - 1] * A[i], minV[i - 1] * A[i]));
		ans = ans > maxV[i] ? ans : maxV[i];
	}

	return ans;
}

int main()
{
	int a[] = { 2, 3, -2, 4 };
	cout << maxProduct(a, 4) << endl;
	return 0;
}