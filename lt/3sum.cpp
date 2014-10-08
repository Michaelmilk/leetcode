#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num)
{
	vector<vector<int> > ans;
	
	int size = num.size();
	int next, last, sum;

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

			if (0 == sum)
			{
				vector <int> temp;
				temp.push_back(num[i]);
				temp.push_back(num[next]);
				temp.push_back(num[last]);

				cout << num[i] << "  " << num[next] << "  " << num[last] << endl;

				ans.push_back(temp);

				while (next < last && num[next] == num[next + 1])
				{
					next ++;
				}
				next ++;
				last--;

			}
			else if (0 > sum)
			{
				next ++;
			}
			else
			{
				last--;
			}	
		}
		while (i < size - 1 && num[i] == num[i + 1])
		{
			i++;
		}
	}
	return ans;

}




int main()
{
	vector<int> v;
	int k;
	
	for (int i = 0; i < 6; i++)
	{
		cin >> k;
		v.push_back(k);
	}
	threeSum(v);

	return 0;
}