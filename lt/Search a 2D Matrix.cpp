#include<iostream>
#include <vector>

using namespace std;


bool searchMatrix(vector<vector<int> > &matrix, int target) {
	int rSize = matrix.size();
	int cSize = matrix[0].size();
	int row = -1;

	for (int i = 0; i < rSize; i++)
	{
		if (matrix[i][0] == target)
		{
			return true;
		}

		if (matrix[i][0] > target)
		{
			row = i - 1;
			break;
		}
	}

	if (-1 == row)
	{
		row = rSize - 1;
	}

	for (int i = 0; i < cSize; i++)
	{
		if (matrix[row][i] == target)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	vector<vector<int> > matrix =
	{ { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } }; 

	cout << searchMatrix(matrix, 3) << endl;
	return 0;
}