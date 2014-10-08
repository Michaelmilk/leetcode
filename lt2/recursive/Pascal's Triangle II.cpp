#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


vector<int> getRow(int rowIndex)
{
	vector<int> ans;
	ans.push_back(1);
	for (int i = 0; i <= rowIndex; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (j == i)
			{
				ans.push_back(1);
			}
			else
			{
				ans[j] = ans[j] + ans[j - 1];
			}
		}
	}

	return ans;
}

int  main()
{

	vector<int> ans = getRow(3);

	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	return 0;
}