#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

/*
int maxArea(vector<int> &height) {
	int max = 0;
	int size = height.size();
	int left = 0;
	int right = size - 1;
	int temp;

	while (left < right)
	{
		temp = min(height[left], height[right]) * (right - left);
		max = max >  temp ? max : temp;

		if (height[left] > height[right])
		{
			right--;
		} 
		else
		{
			left++;
		}
	}
	return max;
}*/

int maxArea(vector<int> &height)
{
	int max = 0;
	int size = height.size();
	int left = 0;
	int right = size - 1;
	int temp;

	while (left < right)
	{
		temp = min(height[left], height[right]) * (right - left);
		max = max >  temp ? max : temp;
		if (height[left] > height[right])
		{			//right--;
			int rightNum = height[right];
			while (right-- > left && rightNum > height[right]);
		}
		else
		{
			//left++;
			int leftNum = height[left];
			while (left++ < right && leftNum > height[left]);
		}
	}
	return max;
}

int main()
{
	vector<int> v = { 2, 1, 3, 6, 5 };
	cout << maxArea(v) << endl;
	return 0;
}