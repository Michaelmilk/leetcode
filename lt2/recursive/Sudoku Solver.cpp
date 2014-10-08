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

bool solve(int rSize, int cSize, vector<vector<char> > &board)
{
	for (int i = 0; i < rSize; i++)
	{
		for (int j = 0; j < cSize; j++)
		{
			if (board[i][j] == '.')
			{
				for (int k = 1; k <= 9; k++)
				{
					board[i][j] = k + 48;
					//递归的返回条件
					if (isValid(i, j, rSize, cSize, board)
						&& solve(rSize, cSize, board))
					{
						return true;//
					}
					board[i][j] = '.';//所有的数字测试过之后，仍然没有有效值，则返回上一层递归，此时需要将当前的值设回“."
				}
				return false;//
			}
		}
	}
	//for循环结束的时候表示已经全部填好（如果“.”不是最后一个方格的值）
	return true;
}

void solveSudoku(vector<vector<char> > &board)
{
	int rSize = board.size();
	if (0 == rSize)
	{
		return;
	}

	int cSize = board[0].size();

	solve(rSize, cSize, board);
}

int main()
{
	return 0;
}