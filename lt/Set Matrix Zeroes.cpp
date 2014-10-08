#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> > &matrix)
{
	int rsize = matrix.size();
	if (0 == rsize)
	{
		return;
	}
	
	int csize = matrix[0].size();
	bool rZero = false;
	bool cZero = false;

	for (int i = 0; i < csize; i++)
	{
		if (0 == matrix[0][i])
		{
			rZero = true;
		}
	}
	
	for (int i = 0; i < rsize; i++)
	{
		if (0 == matrix[i][0])
		{
			cZero = true;
		}
	}
	//将第一行第一列作为标记，然后第一行或者第一列为零值所对应的列和行全部赋值为零
	for (int i = 1; i < rsize; i++)
	{
		for (int j = 1; j < csize; j++)
		{
			if (0 == matrix[i][j])
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < rsize; i++)
	{
		for (int j = 1; j < csize; j++)
		{
			if (0 == matrix[i][0] || 0 == matrix[0][j])
			{
				matrix[i][j] = 0;
			}
		}
	}

	if (rZero)
	{
		for (int i = 0; i < csize; i++)
		{
			matrix[0][i] = 0;
		}
	}

	if (cZero)
	{
		for (int i = 0; i < rsize; i++)
		{
			matrix[i][0] = 0;
		}
	}
}