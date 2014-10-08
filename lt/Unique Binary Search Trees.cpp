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
		for (int left = 0; left < i; left++)//lef从0开始是因为刚开始左子树位零个节点的情况
		{
			int lways = dp[left];
			int rways = dp[i - left - 1];//-1是为了除去根节点
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