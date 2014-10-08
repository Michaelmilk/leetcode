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
		int duplicate = 1;//��Ϊ���û�е��뵱ǰ���ظ���ô���ǵ�ǰ��

		for (int j = 0; j < size; j++)//�������������õ���ͬһֱ���ϵĵ�
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