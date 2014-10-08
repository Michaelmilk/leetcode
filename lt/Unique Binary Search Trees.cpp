#include <iostream>

using namespace std;

int numTrees(int n)
{
	int ret;

	int *dp = new int[n + 1];

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = 0;
		for (int left = 0; left < i; left++)//lef��0��ʼ����Ϊ�տ�ʼ������λ����ڵ�����
		{
			int lways = dp[left];
			int rways = dp[i - left - 1];//-1��Ϊ�˳�ȥ���ڵ�
			dp[i] += lways * rways;
		}
	}
	ret = dp[n];

	return ret;
}

int main()
{
	int ans = numTrees(4);
	cout << ans << endl;
	return 0;
}