#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <Windows.h>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>

using namespace std;

int findMin(vector<int> &num)
{
	int size = num.size();
	int left = 0;
	int right = size - 1;
	int min = INT_MAX;

	while(left < right)
	{
		int mid = (left + right) / 2;

		if (num[left] < num[mid])
		{
			if (num[left] >= num[right])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
			
		}
		else if (num[left] > num[mid])
		{
			right = mid;//因为最小的数要么在mid之前要么就是mid
		}
		else
		{
			for (int i = 0; i <= mid; i++)//查找到mid之前的最小值并保存，然后再二分mid之后的数据
			{
				min = min < num[i] ? min : num[i];
			}
			left = mid + 1;
		}
	}

	return min = min < num[left] ? min : num[left];
}

int main()
{
	vector<int> num = { 3, 3, 1, 3, 3, 3, 3, 3 };//{1, 5, 0, 1, 1, 1, 1};
	cout << findMin(num) << endl;
	return 0;
}
