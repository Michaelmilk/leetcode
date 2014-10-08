#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/*
vector<vector<int> > generate(int numRows)
{
	vector<vector<int> > ret(numRows, vector<int>(numRows));
	vector<int> v;
	vector<vector<int> > ans;
	if (0 == numRows)
	{
		return ret;
	}

	for (int i = 0; i < numRows; i++)
	{
			ret[i][0] = 1;
			ret[i][i] = 1;
	}
	
	for (int i = 3; i <= numRows; i++)
	{
		for (int j = 1; j < i; j++)
		{
			ret[i - 1][j] = ret[i - 2][j - 1] + ret[i - 2][j];
		}
	}
	
	
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			v.push_back(ret[i][j]);
		}
		ans.push_back(v);
		v.clear();
	}
	
	return ans;
}
*/

vector<vector<int> > generate(int numRows)
{
	vector<vector<int> > ret;
	vector<int> v;
	if (0 == numRows)
	{
		return ret;
	}

	if (1 == numRows)
	{
		ret.push_back(vector<int>(1, 1));
		return ret;
	}

	if (2 == numRows)
	{
		ret.push_back(vector<int>(1, 1));
		ret.push_back(vector<int>(2, 1));
		return ret;
	}

	if (3 <= numRows)
	{
		ret.push_back(vector<int>(1, 1));
		ret.push_back(vector<int>(2, 1));
	}
	
	for (int i = 3; i <= numRows; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (0 == j || i - 1 == j)
			{
				v.push_back(1);
				continue;
			}
			v.push_back(ret[i - 2][j - 1] + ret[i - 2][j]);
		}
		ret.push_back(v);
		v.clear();
	}

	return ret;
}


int main()
{
	vector<vector<int> > ans = generate(5);
	ostream_iterator<int> ofile(cout, " ");
	int size = ans.size();

	for (int i = 0; i < size; i++)
	{
		copy(ans[i].begin(), ans[i].end(), ofile);
		cout << endl;
	}
	
	return 0;
}