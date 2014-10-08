#include <iostream>
#include<vector>

using namespace std;

int maxProfits(vector<int> &prices)
{
	int len = prices.size();
	int min = 0;
	int maxProfit = 0;
	
	if (!prices.size())
	{
		return 0;
	}
	maxProfit = 0;
	min = prices[0];
	for (int i = 1; i < len; i++)
	{
		maxProfit = ((prices[i] - min) > maxProfit) ? (prices[i] - min) : maxProfit;
		min = (min > prices[i]) ? prices[i] : min;
	}
	return maxProfit;
}

int main()
{
	vector <int> vec(1);

	for (int i = 0; i < 1; i ++)
	{
		cin >> vec[i];
	}

	int ans = maxProfits(vec);

	cout << ans << endl;

	return 0;
}