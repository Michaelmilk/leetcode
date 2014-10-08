#include <iostream>
#include <vector>

using namespace std;


vector<vector<int> > generateMatrix(int n)
{
	vector<vector<int> > matrix(n, vector<int>(n));
	
	int cur = 1;

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n - i - 1; j++)
		{
			matrix[i][j] = cur++;
		}

		for (int j = i; j < n - i - 1; j++)
		{
			matrix[j][n - i - 1] = cur++;
		}
		
		for (int j = n - i - 1; j > i; j--)
		{
			matrix[n - i - 1][j] = cur++;
		}

		for (int j = n - i - 1; j > i; j--)
		{
			matrix[j][i] = cur++;
		}
	}
	
	if (n % 2)
	{
		matrix[n / 2][n / 2] = cur;
	}
	
	return matrix;
}

int main()
{

	return 0;
}