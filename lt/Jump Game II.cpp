#include <iostream>
#include <vector>

using namespace std;


int jump(int A[], int n)
{
	vector<int> dp(n, n);
	int k;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 0; i < n; i++)
	{
		if (i > 0 && A[i] < A[i - 1])//前一个下标位置到后面的值肯定小于或者等于后一个下标到后面位置的值，如果后一直小雨前一个值，那么后一个下标能够到达后面的位置肯定已经被前一个之所覆盖了！
		{
			continue;
		}
		
		k = (A[i] + i > n - 1) ? n - 1 : A[i] + i;
		for (int j = k; j > 1; j--)
		{
			if (dp[i] + 1 < dp[j])
			{
				dp[j] = dp[i] + 1;
			}
		}
		
	}

	for (int i = 0; i < n; i ++)
	{
		cout << dp[i] << endl;
	}
	
	return dp[n - 1];
}

int main()
{
	int a[] = { 3, 2, 1 };//{ 2, 3, 1, 1, 4 };

	cout << jump(a, 3) << endl;
	return 0;
}