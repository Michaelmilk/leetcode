#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int candy(vector<int> &ratings)
{
	int ans = 0;
	int len = ratings.size();
	int count = 1;
	vector<int> vec(len, 0);

	for (int i = 1; i < len; i ++)
	{
		if (ratings[i] > ratings[i - 1])
		{
			vec[i] = max(count ++, vec[i]);
		}
		else
		{
			count = 1;
		}
	}

	count = 1;
	for (int i = len - 2; i >= 0; i --)
	{
		if (ratings[i] > ratings[i + 1])
		{
			vec[i] = max(count++, vec[i]);
		}
		else
		{
			count = 1;
		}
	}

	ans = len;
	for (int i = 0; i < len; i ++)
	{
		ans += vec[i];
	}
	return ans;
}

int main()
{
	vector<int> vec;
	int n;
	int num;

	//vector<int> vec(5, 0);

	//cout << vec[0] << endl << vec[3] << endl;

	cin >> n;

	while (n --)
	{
		cin >> num;
		vec.push_back(num);
	}

	int ans = candy(vec);

	cout << ans << endl;

	return 0;
}