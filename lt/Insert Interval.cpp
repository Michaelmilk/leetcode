#include <iostream>
#include <vector>
#include <algorithm>
#include<windows.h>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}

};
/*
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	int size = intervals.size();
	vector<Interval> ret;

	if (0 == size)
	{
		intervals.push_back(newInterval);
		return intervals;
	}

	if (newInterval.end < intervals[0].start)
	{
		ret = intervals;
		ret.insert(ret.begin(), newInterval);
		return ret;
	}

	if (newInterval.start > intervals[size - 1].end)
	{
		ret = intervals;
		ret.insert(ret.end(), newInterval);
		return ret;
	}

	int startPos = -1;
	int endPos = -1;
	for (int i = 0; i < size; i++)
	{
		if (newInterval.start >= intervals[i].start)//�ҵ�start�Ȳ���ֵ��startС�����һ���ڵ�
		{
			startPos = i;
		}

		if (newInterval.end <= intervals[i].end)
		{
			endPos = i;
			break;
		}
	}
	
	if (startPos == endPos && endPos != -1)
	{
		return intervals;
	}
	
	if (startPos == endPos && endPos == -1)
	{
		ret.push_back(newInterval);
		return ret;
	}

	if (startPos != endPos && endPos == -1)
	{
		if (intervals[startPos].end >= newInterval.start)
		{
			for (int i = 0; i < startPos; i++)
			{
				ret.push_back(intervals[i]);
			}
			Interval tmp(intervals[startPos].start, newInterval.end);
			ret.push_back(tmp);
			return ret;
		}
		else
		{
			for (int i = 0; i <= startPos; i++)
			{
				ret.push_back(intervals[i]);
			}
			ret.push_back(newInterval);
			return ret;
		}
		
		
	}

	if (startPos != endPos && startPos == -1)
	{
		Interval tmp(newInterval.start, max(intervals[endPos].end, newInterval.end));
		ret.push_back(tmp);
		for (int i = endPos + 1; i < size; i++)
		{
			ret.push_back(intervals[i]);
		}
		return ret;
	}

	if (startPos < endPos)
	{
		if (newInterval.start <= intervals[startPos].end && 
			newInterval.end >= intervals[endPos].start) //��Ҫ�ϲ�[1,3],[6,9]<-[2,7] 
		{
			for (int i = 0; i < startPos; i++)
			{
				ret.push_back(intervals[i]);
			}
			Interval tmp(intervals[startPos].start, intervals[endPos].end);
			ret.push_back(tmp);
			for (int i = endPos + 1; i < size; i++)
			{
				ret.push_back(intervals[i]);
			}

			return ret;
		}
		else if (newInterval.start <= intervals[startPos].end &&
			newInterval.end <= intervals[endPos].start) //��Ҫ�ϲ�[1,3],[6,9]<-[2,5]
		{
			for (int i = 0; i < startPos; i++)
			{
				ret.push_back(intervals[i]);
			}
			Interval tmp(intervals[startPos].start, newInterval.end);
			ret.push_back(tmp);
			for (int i = endPos; i < size; i++)
			{
				ret.push_back(intervals[i]);
			}

			return ret;
		}
		else if (newInterval.start > intervals[startPos].end &&	//����Ҫ�ϲ�ֻҪ����[1,3],[7,8],[11,12]<-[6,10] 
			newInterval.end < intervals[endPos].start)
		{
			for (int i = 0; i <= startPos; i++)
			{
				ret.push_back(intervals[i]);
			}
			ret.push_back(newInterval);
			for (int i = endPos; i < size; i++)
			{
				ret.push_back(intervals[i]);
			}

			return ret;
		}
		else if (newInterval.start >= intervals[startPos].end &&
			newInterval.end >= intervals[startPos].start)//[1,3],[6,9]<-[4,7] 
		{
			for (int i = 0; i <= startPos; i++)
			{
				ret.push_back(intervals[i]);
			}
			Interval tmp(newInterval.start, intervals[endPos].end);
			ret.push_back(tmp);
			for (int i = endPos + 1; i < size; i++)
			{
				ret.push_back(intervals[i]);
			}

			return ret;
		}
	}
}
*/

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
     vector<Interval> ret;
     for (int i = 0; i < intervals.size(); ++i)
	 {
       if (intervals[i].end < newInterval.start)//left  ���½ڵ�С��ȫ������ǰ��
         {
             ret.push_back(intervals[i]);
         }
       else if (intervals[i].start > newInterval.end)//right  ���½ڵ��ģ����Ȱ��½ڵ���룬Ȼ�����Ľڵ�ȫ�����ں���
         {
             ret.push_back(newInterval);
             while (i < intervals.size())
                    ret.push_back(intervals[i++]);
         }
       else//overlap  ���µĽڵ��ԭ�Ƚڵ��غϵĽڵ���ݴ�С������Ϊһ���µĽڵ�
         {
             newInterval.start = min(newInterval.start, intervals[i].start);
             newInterval.end = max(newInterval.end, intervals[i].end);
         }
	 }
	 if (0 == ret.size() || ret.back().end < newInterval.start)//���µĽڵ����������ҽڵ����غϵ�����Լ���ǰ�ڵ�Ϊ�յ����
       ret.push_back(newInterval);
     return ret;
	
}


int main()
{
	vector<Interval> v = { Interval(1, 3), Interval(6, 7)};
		//{ Interval(1, 2), Interval(3, 5), Interval(6, 7), 
		//Interval(8, 10), Interval(12, 16) };
	//{ Interval(1, 3), Interval(6, 9) };
		
	Interval v1(4, 5);

	vector<Interval> v2 = insert(v, v1);

	int size = v2.size();

	for (int i = 0; i < size; i++)
	{
		cout << v2[i].start << " " << v2[i].end << endl;
	}

	return 0;
}