#include <iostream>
#include <vector>
#include <map>
using namespace std;

enum OrderBy
{
	ASCENDING,
	DECENGING
};

//主要的时间复杂度都浪费在找连续序列上了。
//怎么能减少找连续序列的时间复杂度？经过观察我们可以发现，
//4的最长序列和3，2，1的最长序列其实是一样的。
//找过了4之后其实后面这3个数都不用找了。
map<int, int> mp;

int countConsecutiveNum(OrderBy orderBy, int value)
{
	int maxLen = 0;

	while (mp.find(value) != mp.end() && mp[value] == 1)
	{
		maxLen++;

		mp[value] = 0;//如果已经查找过了，就不用再找了！

		if (orderBy == ASCENDING)
		{
			value++;
		} 
		else
		{
			value--;
		}
	}

	return maxLen;
}

int longestConsecutive(vector<int> &num)
{
	int size = num.size();

	for (int i = 0; i < size; i++)
	{
		mp[num[i]] = 1;
	}

	int maxLen = 0;

	for (int i = 0; i < size; i++)
	{
		int ascendLen = countConsecutiveNum(ASCENDING, num[i]);//查找比当前元素大的连续的数
		int descendLen = countConsecutiveNum(DECENGING, num[i] - 1);//查找比当前元素小的连续的数

		if (ascendLen + descendLen > maxLen)
		{
			maxLen = ascendLen + descendLen;
		}
	}
	
	return maxLen;
}


int main()
{
	vector<int> v = { 100, 4, 200, 1, 3, 2 };
	cout << longestConsecutive(v) << endl;
	return 0;
}
