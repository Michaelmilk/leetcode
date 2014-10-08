#include <iostream>
#include <vector>
#include <array>

using namespace std;

/*
bool isValidSudoku(vector<vector<char> > &board)
{
	//int size = board.size();
	int rowSize = 9;
	int colSize = 9;
	int row = 0;
	//int col = 0;

// 	for (int i = 0; i < 9; i++)
// 	{
// 		for (int j = 0; j < 9; j++)
// 		{
// 			cout << board[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
	vector<vector<char> > v;// (9, vector<char>(9));
	vector<char> v1;
	row = 0;
	for (int i = 0; i < 9; i += 3)
	{
		for (int t = 0; t < 9; t += 3)
		{
			for (int j = i; j < i + 3; j++)
			{
				for (int k = t; k < t + 3; k++)
				{
					v1.push_back(board[j][k]);
				}
			}
			v.push_back(v1);
			v1.clear();
		}
	}

// 	for (int i = 0; i < 9; i++)
// 	{
// 		for (int j = 0; j < 9; j++)
// 		{
// 			cout << v[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
	
	for (row = 0; row < rowSize; row++)
	{
		for (int i = colSize - 1; i >= 0; i--)
		{
			if (board[row][i] != '.')
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (board[row][j] != '.')
					{
						if (board[row][i] == board[row][j])
						{
							return false;
						}
					}
					else
					{
						continue;
					}
					
				}
			}
			else
			{
				continue;
			}
		}

		for (int i = rowSize - 1; i >= 0; i--)
		{
			if (board[i][row] != '.')
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (board[j][row] != '.')
					{
						if (board[i][row] == board[j][row])
						{
							return false;
						}
					}
					else
					{
						continue;
					}
					
				}
			}
			else
			{
				continue;
			}
		}
	}

// 	vector<vector<char> > v;// (9, vector<char>(9));
// 	vector<char> v1;
// 	row = 0;
// 	for (int i = 0; i < 9; i += 3)
// 	{
// 		for (int t = 0; t < 9; t += 3)
// 		{
// 			for (int j = i; j < i + 3; j++)
// 			{
// 				for (int k = t; k < t + 3; k++)
// 				{
// 					v1.push_back(board[j][k]);
// 				}
// 			}
// 			v.push_back(v1);
// 			v1.clear();
// 		}
// 	}
// 
// 	for (int i = 0; i < 9; i++)
// 	{
// 		for (int j = 0; j < 9; j++)
// 		{
// 			cout << v[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
	

	for (row = 0; row < rowSize; row ++)
	{
		for (int i = colSize - 1; i >= 0; i--)
		{
			if (v[row][i] != '.')
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (v[row][j] != '.')
					{
						if (v[row][i] == v[row][j])
						{
							return false;
						}
					}
					else
					{
						continue;
					}
				}
			}
			else
			{
				continue;
			}
		}

	}

	return true;
}*/

bool isValidSudoku(vector<vector<char> > &board)
{
	array<bool, 9> row[9];
	array<bool, 9> col[9];
	array<bool, 9> box[9];

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			row[i][j] = col[i][j] = box[i][j] = false;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char ch = board[i][j];

			if (ch == '.')
			{
				continue;
			}

			int index = ch - '1';

			if (row[i][index])//每一行
			{
				return false;
			}
			row[i][index] = true;

			if (col[j][index])//每一列
			{
				return false;
			}
			col[j][index] = true;

			if (box[i / 3 * 3 + j / 3][index])
			{
				return false;
			}
			box[i / 3 * 3 + j / 3][index] = true;
		}
	}
	
	return true;
}


int main()
{
	vector<vector<char> > board;//(9, vector<char>(9));

	
	//board[0] = { '.', '8', '7','6', '5', '4', '3', '2', '1' };
	vector<char> board0, board1, board2, board3, board4, board5, board6, board7, board8;

	board0.push_back('.');
	board0.push_back('.');
	board0.push_back('.');
	board0.push_back('.');
	board0.push_back('5');
	board0.push_back('.');
	board0.push_back('.');
	board0.push_back('1');
	board0.push_back('.');
	board1.push_back('.');
	board1.push_back('4');
	board1.push_back('.');
	board1.push_back('3');
	board1.push_back('.');
	board1.push_back('.');
	board1.push_back('.');
	board1.push_back('.');
	board1.push_back('.');
	board2.push_back('.');
	board2.push_back('.');
	board2.push_back('.');
	board2.push_back('.');
	board2.push_back('.');
	board2.push_back('3');
	board2.push_back('.');
	board2.push_back('.');
	board2.push_back('1');
	board3.push_back('8');
	board3.push_back('.');
	board3.push_back('.');
	board3.push_back('.');
	board3.push_back('.');
	board3.push_back('.');
	board3.push_back('.');
	board3.push_back('2');
	board3.push_back('.');
	board4.push_back('.');
	board4.push_back('.');
	board4.push_back('2');
	board4.push_back('.');
	board4.push_back('7');
	board4.push_back('.');
	board4.push_back('.');
	board4.push_back('.');
	board4.push_back('.');
	board5.push_back('.');
	board5.push_back('1');
	board5.push_back('5');
	board5.push_back('.');
	board5.push_back('.');
	board5.push_back('.');
	board5.push_back('.');
	board5.push_back('.');
	board5.push_back('.');
	board6.push_back('.');
	board6.push_back('.');
	board6.push_back('.');
	board6.push_back('.');
	board6.push_back('.');
	board6.push_back('2');
	board6.push_back('.');
	board6.push_back('.');
	board6.push_back('.');
	board7.push_back('.');
	board7.push_back('2');
	board7.push_back('.');
	board7.push_back('9');
	board7.push_back('.');
	board7.push_back('.');
	board7.push_back('.');
	board7.push_back('.');
	board7.push_back('.');
	board8.push_back('.');
	board8.push_back('.');
	board8.push_back('4');
	board8.push_back('.');
	board8.push_back('.');
	board8.push_back('.');
	board8.push_back('.');
	board8.push_back('.');
	board8.push_back('.');

	board.push_back(board0);
	board.push_back(board1);
	board.push_back(board2);
	board.push_back(board3);
	board.push_back(board4);
	board.push_back(board5);
	board.push_back(board6);
	board.push_back(board7);
	board.push_back(board8);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	bool b = isValidSudoku(board);
	cout << b << endl;
	//{ ".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........" };
	return 0;
}