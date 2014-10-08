#include <iostream>
#include <vector>

using namespace std;

bool canJump(int A[], int n) {
	if (1 == n)
	{
		return true;
	}

	vector<bool> dp(n, 0);
	if (0 == A[0])
	{
		return false;
	}
	int k;
	int count = 0;

	dp[0] = 1;//第i个点是否可达，只测试之前能够到达的点
	//dp[1] = 1;

	for (int i = 0; i < n; i++)
	{
		if (i > 0 && A[i] + 1 <= A[i - 1])
		{
			continue;
		}
	
		k = A[i] + i;
		
		if (dp[i])//第i个点是否可达，只测试之前能够到达的点
		{
			if (n - 1 == k)
			{
				return true;
			}
			for (int j = k; j > i; j--)
			{
				dp[j] = true;
				dp[A[j] + j] = true;

				if (A[j] + j >= n - 1)
				{
					return true;
				}
			/*	if (A[j] + j == j)
				{
					count++;
				}*/
			}
			/*if (count == k - i)
			{
				return false;
			}*/
		}


	}

	return false;
}
int main()
{
	int a[] = { 2, 1, 0, 0};//{ 2, 3, 1, 1, 4 };

	cout << canJump(a, 4) << endl;
	return 0;
}
