#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
	int size = gas.size();
	int idx = -1;
	int rest = 0;
	int count = 0;
	int base = size;
	int round = 0;

	if (1 == base)
	{	
		return gas[0] >= cost[0] ? 0 : -1;
	}
	for (int i = 0; i < size; i++)
	{
		if (gas[i % base] + rest >= cost[i % base])
		{
			rest += gas[i % base] - cost[i % base];
			count++;
			if (base == count)
			{
				idx = i % base + 1;
			}
		}
		else
		{
			round++;
			if (round >= base)
			{
				break;
			}
			count = 0;
			size += i + 1;
			rest = 0;
		}

	}

	return idx;
}

int main()
{
	vector<int> v1 = {2,1,2,5};
	vector<int> v2 = {1,2,3,3};
	cout << canCompleteCircuit(v1, v2) << endl;
}