#include <iostream>
#include <vector>

using namespace std;

bool isValid(int r, int c, int rSize, int cSize, vector<vector<char> > &board)
{
	for (int i = 0; i < cSize; i++)
	{
		if (i != c && board[r][c] == board[r][i])
		{
			return false;
		}
	}

	for (int i = 0; i < rSize; i++)
	{
		if (i != r && board[r][c] == board[i][c])
		{
			return false;
		}
	}

	for (int i = (r / 3) * 3; i < (r / 3 + 1) * 3; i++)
	{
		for (int j = (c / 3) * 3; j < (c / 3 + 1) * 3; j++)
		{
			if (i != r && j != c && board[i][j] == board[r][c])
			{
				return false;
			}
		}
	}

	return true;
}

bool isValidSudoku(vector<vector<char> > &board)
{
	int rSize = board.size();
	if (0 == rSize)
	{
		return false;
	}

	int cSize = board[0].size();

	for (int i = 0; i < rSize; i++)
	{
		for (int j = 0; j < cSize; j++)
		{
			if (board[i][j] != '.')
			{
				if (!isValid(i, j, rSize, cSize, board))
				{
					return false;
				}
			}
		}
	}

	return true;
}

int main()
{
	return 0;
}