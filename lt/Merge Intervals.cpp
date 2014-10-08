#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
if (0 == i)
{
	if (intervals[i].start <= intervals[i + 1].start &&
		intervals[i].end >= intervals[i + 1].start)
	{
		ret.push_back(Interval(intervals[i].start, intervals[i + 1].end));
		i++;

	}
	else
	{
		ret.push_back(intervals[i]);
	}
}*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

bool cmp(const Interval &a, const Interval &b)
{
	if (a.start == b.start)
	{
		return a.end < b.end;
	}
	else
	{
		return a.start < b.start;
	}
	
};

vector<Interval> merge(vector<Interval> &intervals)
{
	int size = intervals.size();
	vector<Interval> ret;

	sort(intervals.begin(), intervals.end(), cmp);

	for (int i = 0; i < size; i++)
	{
		if (0 == i)
		{
			ret.push_back(intervals[i]);
		}
		else
		{
			int s = ret.size();
			if (ret[s - 1].start <= intervals[i].start &&				ret[s - 1].end >= intervals[i].start)
			{
				int end = intervals[i].end > ret[s - 1].end ? intervals[i].end : ret[s - 1].end;
				ret[s - 1].end = end;
			}
			else
			{
				ret.push_back(intervals[i]);
			}
		}
	}

	return ret;
}

/*//TLE
vector<Interval> merge(vector<Interval> &intervals)
{
	int size = intervals.size();
	vector<Interval> ret;

	sort(intervals.begin(), intervals.end(), cmp);

	for (int i = 0; i < size;)
	{
		if (intervals[i].end <= intervals[i + 1].start)
		{
			i++;
			continue;
		}
		if (i + 1 < size && intervals[i].start <= intervals[i + 1].start &&
			intervals[i].end >= intervals[i + 1].start && 
			intervals[i].end <= intervals[i + 1].end)
		{
			Interval tmp = Interval(intervals[i].start, intervals[i + 1].end);
			intervals.erase(intervals.begin() + i);
			intervals.erase(intervals.begin() + i);
			intervals.insert(intervals.begin() + i, tmp);
			size = intervals.size();
		}
		else if (i + 1 < size && intervals[i].start <= intervals[i + 1].start &&
			intervals[i].end >= intervals[i + 1].end)
		{
			Interval tmp = Interval(intervals[i].start, intervals[i].end);
			intervals.erase(intervals.begin() + i);
			intervals.erase(intervals.begin() + i);
			intervals.insert(intervals.begin() + i, tmp);
			size = intervals.size();
		}
		else
		{
			i++;
		}
	}

	return intervals;
}*/

int main()
{
	vector<Interval> v = {Interval(1, 10), Interval(2, 6),
		Interval(8, 10), Interval(15, 18) };

	merge(v);
	
	int size = v.size();

	for (int i = 0; i < size; i++)
	{
		cout << v[i].start << " " << v[i].end << endl;
	}
	
	return 0;
}