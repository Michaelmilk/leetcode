#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int threeSum(vector<int> &num, int target)
{
	int size = num.size();
	int next, last, sum, ans;
	int min = INT_MAX;

	sort(num.begin(), num.end());

	//num.erase(unique(num.begin(), num.end()), num.end());
	//size = num.size();

	for (int i = 0; i < size; i ++)
	{
		next = i + 1;
		last = size - 1;

		while (next < last)
		{
			sum = num[i] + num[next] + num[last];

			if (sum == target)
			{
				ans = sum;
				min = 0;

				break;


				cout << num[i] << "  " << num[next] << "  " << num[last] << endl;
				
// 				while (next < last && num[next] == num[next + 1])
// 				{
// 					next++;
// 				}
// 				next++;
// 				last--;

			}
			else if (target > sum)
			{
				if (target - sum < min)
				{
					min = target - sum;
					ans = sum;
				}

				next ++;
			}
			else
			{
				if (sum - target < min)
				{
					min = sum - target;
					ans = sum;
				}
				last--;
			}	
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
	
	for (int i = 0; i < 4; i++)
	{
		cin >> k;
		v.push_back(k);
	}
	
	cout << threeSum(v, target) << endl;

	return 0;
}
