#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num, int target)
{
	vector<vector<int> > ans;

	int size = num.size();
	int next, last, sum;

	sort(num.begin(), num.end());

	//num.erase(unique(num.begin(), num.end()), num.end());
	//size = num.size();
	for (int k = 0; k < size - 3; k ++)
	{

		for (int i = k + 1; i < size - 2; i++)
		{
			next = i + 1;
			last = size - 1;

			while (next < last)
			{
				sum = num[k] + num[i] + num[next] + num[last];

				if (target == sum)
				{
					vector <int> temp;
					temp.push_back(num[k]);
					temp.push_back(num[i]);
					temp.push_back(num[next]);
					temp.push_back(num[last]);

					cout << num[k] << "  " << num[i] << "  " << num[next] << "  " << num[last] << endl;

					ans.push_back(temp);

					while (next < last && num[next] == num[next + 1])
					{
						next++;
					}
					next++;
					last--;

				}
				else if (target > sum)
				{
					next++;
				}
				else
				{
					last--;
				}
			}
			while (i < size - 2 && num[i] == num[i + 1])
			{
				i++;
			}

		}
		while (k < size - 3 && num[k] == num[k + 1])
		{
			k++;
		}
	}
	return ans;

}




int main()
{
	vector<int> v;
	int k;
	int target;

	cin >> target;

	for (int i = 0; i < 6; i++)
	{
		cin >> k;
		v.push_back(k);
	}
	threeSum(v, target);

	return 0;
}