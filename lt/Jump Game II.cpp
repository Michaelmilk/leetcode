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
		if (i > 0 && A[i] < A[i - 1])//ǰһ���±�λ�õ������ֵ�϶�С�ڻ��ߵ��ں�һ���±굽����λ�õ�ֵ�������һֱС��ǰһ��ֵ����ô��һ���±��ܹ���������λ�ÿ϶��Ѿ���ǰһ��֮�������ˣ�
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