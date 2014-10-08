#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &num)
{
	int size = num.size();

	if (0 == size || 1 == size)
	{
		return;
	}

	vector<int>::iterator it;
	vector<int>::iterator first;
	vector<int>::iterator last;
	first = num.begin();
	last = num.end();
	it = last;
	it--;

	while (1)
	{
		vector<int>::iterator itTmp = it;
		it--;
		
		if (*it < *itTmp)
		{
			vector<int>::iterator itTmp2 = last;
 			while (*it >= *(--itTmp2));

			iter_swap(it, itTmp2);
			reverse(itTmp, last);
			break;
		}

		if (it == first)
		{
			reverse(first, last);
			break;
		}
	}
}

int main()
{
	vector<int> v = {1, 5, 1};//{ 5, 5, 4, 7, 6, 3, 2};

	nextPermutation(v);

	int length = v.size();
	for (int i = 0; i < length; i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}