#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*time exceed
int maxSun(vector<int> p)
{
	
	int len = p.size();

	if (1 >= len)
	{
		return 0;
	}

	int maxProfits = 0;
	int min = p[0];

	for (int i = 0; i < len; i ++)
	{
		maxProfits = (p[i] - min) > maxProfits ? (p[i] - min) : maxProfits;
		min = p[i] > min ? min : p[i];
	}
	return maxProfits;
}

int maxProfit(vector<int> prices)
{
	int maxP = 0;
	int len = prices.size();
	vector<int> left;
	vector<int> right;

	if (1 >= len)
	{
		return 0;
	}
	for (int i = 0; i < len; i ++)
	{
		left.clear();
		for (int j = 0; j <= i; j ++)
		{
			left.push_back(prices[j]);
		}

		right.clear();
		for (int k = i + 1; k <= len - 1; k++)
		{
			right.push_back(prices[k]);
		}
		int lsum = maxSun(left);
		int rsum = maxSun(right);
		int csum = lsum + rsum;
		maxP = maxP >= csum ? maxP : csum;
	}
	return maxP;
}
*/


/*
int maxProfit(vector<int> &prices) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function

	int size = prices.size();
	if (size == 0)
		return 0;

	vector<int> f1(size);
	vector<int> f2(size);

	int minV = prices[0];
	for (int i = 1; i < size; i++){
		minV = std::min(minV, prices[i]);
		f1[i] = std::max(f1[i - 1], prices[i] - minV);
	}

	int maxV = prices[size - 1];
	f2[size - 1] = 0;
	for (int i = size - 2; i >= 0; i--){
		maxV = std::max(maxV, prices[i]);
		f2[i] = std::max(f2[i + 1], maxV - prices[i]);
	}

	int sum = 0;
	for (int i = 0; i < size; i++)
		sum = std::max(sum, f1[i] + f2[i]);

	return sum;
}
*/


int maxProfit(vector<int> prices)
{
	int maxP = 0;
	int len = prices.size();
	vector<int> left;
	vector<int> right;

	if (1 >= len)
	{
		return 0;
	}

	vector<int> f1(len);
	vector<int> f2(len);

	int minV = prices[0];
	for (int i = 1; i < len; i ++)
	{
		minV = min(minV, prices[i]);
		f1[i] = max(f1[i - 1], prices[i] - minV);
	}

	int maxV = prices[len - 1];
	for (int j = len - 2; j >= 0; j --)
	{
		maxV = max(maxV, prices[j]);
		f2[j] = max(f2[j + 1], maxV - prices[j]);
	}
	
	for (int k = 0; k < len; k ++)
	{
		maxP = maxP > f1[k] + f2[k] ? maxP : f1[k] + f2[k];
	}

	return maxP;
}

int main()
{
	vector<int> vec(5);

	for (int i = 0; i < 5; i ++)
	{
		cin >> vec[i];
	}

	/*
	vector<int> vec1(vec[1], vec.end());
	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i] << endl;
	}
	*/
	int ans = maxProfit(vec);

	cout << ans << endl;
	return 0;
}