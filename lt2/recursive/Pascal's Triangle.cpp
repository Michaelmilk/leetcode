#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<vector<int> > generate(int numRows)
{
	vector<vector<int> > ans;
	vector<int> buf;

	for (int i = 0; i < numRows; i++)
	{
		buf.clear();
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				buf.push_back(1);
			}
			else
			{
				buf.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
			}
		}
		ans.push_back(buf);
	}

	return ans;
}

int  main()
{

	vector<vector<int> > ans = generate(5);

	int size = ans.size();
	for (int i = 0; i < size; i++)
	{
		copy(ans[i].begin(), ans[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}