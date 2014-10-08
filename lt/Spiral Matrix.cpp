#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

/*
vector<int> spiralOrder(vector<vector<int> > &matrix)
{
	vector<int> ret;
	int size = matrix.size();

	if (0 == size)
	{
		return vector<int>(0);
	}

	int csize = matrix[0].size();

	if (1 == size)
	{
		return matrix[0];
	}
	if (1 == csize)
	{
		for (int i = 0; i < size; i++)
		{
			ret.push_back(matrix[i][0]);
		}
		return ret;
	}
	
	int layer = min(size, csize);

	for (int i = 0; i < layer / 2; i++)
	{
		for (int j = i; j < csize - i - 1; j++)
		{
			ret.push_back(matrix[i][j]);
		}

		for (int j = i; j < size - i - 1; j++)
		{
			ret.push_back(matrix[j][csize - i - 1]);
		}

		for (int j = csize - i - 1; j > i; j--)
		{
			ret.push_back(matrix[size - i - 1][j]);
		}

		for (int j = size - i - 1; j > i; j--)
		{
			ret.push_back(matrix[j][i]);
		}
	}

	layer /= 2;

	if (min(size, csize) % 2)
	{
		if (size > csize)
		{
			for (int i = layer; i <= size - 1 - layer; i++)
			{
				ret.push_back(matrix[i][csize / 2]);
			}
		}
		else
		{
			for (int i = layer; i <= csize - 1 - layer; i++)
			{
				ret.push_back(matrix[size / 2][i]);
			}
		}
	}
	
	return ret;
}*/

vector<int> spiralOrder(vector<vector<int> > &matrix)
{
	vector<int> ret;
	int size = matrix.size();
	if (0 == size)
	{
		return vector<int>();
	}

	int csize = matrix[0].size();

	int x1 = 0;//rows
	int y1 = 0;//columns
	int x2 = size - 1;
	int y2 = csize - 1;

	while (x1 <= x2 && y1 <= y2)
	{
		for (int i = y1; i <= y2; i++)
		{
			ret.push_back(matrix[x1][i]);
		}

		for (int i = x1 + 1; i <= x2; i++)
		{
			ret.push_back(matrix[i][y2]);
		}

		if (x1 != x2)
		{
			for (int i = y2 - 1; i >= y1; i--)
			{
				ret.push_back(matrix[x2][i]);
			}
		}

		if (y1 != y2)
		{
			for (int i = x2 - 1; i > x1; i--)
			{
				ret.push_back(matrix[i][y1]);
			}
		}

		x1++;
		x2--;
		y1++;
		y2--;
	}
	return ret;
}

int main()
{
	vector<vector<int> > matrix=
	{
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }
	};
// 	{
// 		{ 1, 2, 3 },
// 		{ 4, 5, 6 },
// 		//{ 7, 8, 9}
// 	};
// 	vector<int> t1 = { 1, 2, 3 };
// 	vector<int> t1 = { 4, 5, 6 };
// 	vector<int> t1 = { 7, 8, 9 };

	
	vector<int> ret = spiralOrder(matrix);


	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
	
	return 0;
}