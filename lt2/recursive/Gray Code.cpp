#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int> grayCode(int n)
{
	vector<int> ans;
	ans.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int high = 1 << i;
		int size = ans.size();
		for (int j = size - 1; j >= 0; j--)
		{
			//将1加到ans中从后往前顺序的元素中
			ans.push_back(high + ans[j]);
		}
	}

	return ans;
}

int main()
{
	vector<int> ans = grayCode(2);
	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}