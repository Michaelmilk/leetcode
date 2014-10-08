#include <iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
	int maxProfits = 0;
	int len = prices.size();

	if (len == 0)
	{
		return 0;
	}
	for (int i = 1; i < len; i ++)
	{
		if (prices[i] > prices[i -1])
		{
			maxProfits += prices[i] - prices[i - 1];
		}
	}
	return maxProfits;
}

int main()
{
	vector<int> vec(1);

	for (int i = 0; i < 1; i ++)
	{
		cin >> vec[i];
	}

	int ans = maxProfit(vec);

	cout << ans << endl;

	return 0;
}