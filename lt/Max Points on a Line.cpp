#include <iostream>
#include <map>
#include <vector>

using namespace std;


struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points)
{
	int ans = 0;
	map<double, int> mp;
	int size = points.size();

	for (int i = 0; i < size; i++)
	{
		mp.clear();
		mp[INT_MIN] = 0;
		int duplicate = 1;//因为如果没有点与当前点重复那么就是当前点

		for (int j = 0; j < size; j++)//查找其余点中与该点在同一直线上的点
		{
			if (i == j)
			{
				continue;
			}

			if (points[i].x == points[j].x && points[i].y == points[j].y)
			{
				duplicate++;
				continue;
			}

			double idx = points[i].x == points[j].y ? INT_MAX : (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
			mp[idx]++;
		}

		for (map<double, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			ans = it->second + duplicate > ans ? it->second + duplicate : ans;
		}
	}

	return ans;
}