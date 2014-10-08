#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board, int row, int col)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != col && board[row][i] == board[row][col])
		{
			return false;
		}
	}

	for (int j = 0; j < 9; j++)
	{
		if (j != row && board[j][col] == board[row][col])
		{
			return false;
		}
	}

	for (int i = row / 3 * 3; i < (row / 3 + 1) * 3; i++)
	{
		for (int j = col / 3 * 3; j < (col / 3 + 1) * 3; j++)
		{
			if (i != row && j != col && board[i][j] != board[row][col])
			{
				return false;
			}
		}
	}
	return true;
}

bool solve(vector<vector<char> > &board)
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if ('.' == board[row][col])
			{
				for (int i = 1; i <= 9; i++)
				{
					board[row][col] = '0' + i;
					if (isValidSudoku(board, row, col) && solve(board))
					{
						return true;
					}

					board[row][col] = '.';
				}
				return false;
			}
		}
	}
	return true;
}

void solveSudoku(vector<vector<char> > &board)
{
	solve(board);
}

int main()
{
	return 0;
}