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
	int min = 0;
	int size = num.size();

	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int mid = (left + right) / 2;

		if (num[left] <= num[mid])
		{
			if (num[left] > num[right])
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
			if (num[left] > num[right])
			{
				left = left + 1;
			}
		}
	}

	return num[left];
	//return min;
}

int main()
{
	vector<int> num = {6, 7, 0, 1, 2, 4,};
	cout << findMin(num) << endl;
	return 0;
}
