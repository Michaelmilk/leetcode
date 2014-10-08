#include<iostream>
#include <vector>
#include<map>
#include<algorithm>

using namespace std;

vector<int> fun(vector<int>& numbers, int target)
{


	vector<int> res;
	int length = numbers.size();
	if (length < 2)return res;
	map<int, int> mp;
	for (int i = 0; i < length; ++i)
		mp[numbers[i]] = i;
	map<int, int>::iterator it = mp.end();
	for (int i = 0; i < length; ++i)
	{
		it = mp.find(target - numbers[i]);
		if (it != mp.end() && it->second != i)
		{
			/*
			cout << "index1=" << i + 1 << ",";
			cout << "index2=" << it->second + 1;
			*/
			res.push_back(min(i + 1, it->second + 1));
			res.push_back(max(i + 1, it->second + 1));

			break;
		}
	}
	return res;
}

	
struct NODE
{
	int val;
	int index;
	NODE(int v, int i) :val(v), index(i){}
	/*
	bool operator < (const NODE &node) const
	{
		return val < node.val;
	}
	*/
};

bool compare(const NODE &lhs, const NODE &rhs)
 {
     return lhs.val < rhs.val;
 }

vector<int> fun1(vector<int>& numbers, int target)
{
	
	int size = numbers.size();
	vector<int> ret;
	vector<NODE> vec;

	for (int i = 0; i < size; i ++)
	{
		vec.push_back(NODE(numbers[i], i + 1));
	}

	//sort(vec.begin(), vec.end());
	sort(vec.begin(), vec.end(),compare);

	/*
	for (int t = 0; t < size; t ++)
	{
		cout << vec[t].val << " " << endl;
	}
	*/
	
	for (int i = 0; i < size; i ++)
	{
		for (int j = size - 1; j > i; j --)
		{
			if (vec[i].val + vec[j].val < target)
			{
				break;
			}
			
			if (vec[i].val + vec[j].val == target)
			{
				
				cout << "index1=" << vec[i].index << ",";
				cout << "index2=" << vec[j].index;
				
				ret.push_back(min(vec[i].index, vec[j].index));
				ret.push_back(max(vec[i].index, vec[j].index));
				return ret;
			}
		}
	}
	
}

int main()
{
	vector<int> v;
	int k;
	int target;

	cin >> target;
	
	for (int i = 0; i < 3; i ++)
	{
		cin >> k;
		v.push_back(k);
	}
	fun1(v, target);
	
	return 0;
}