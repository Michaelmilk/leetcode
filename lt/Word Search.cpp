#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool findword(vector<vector<char> > &board, int i, int j, string word, int idx)
{
	int rSize = board.size();
	int cSize = board[0].size();
	int len = word.length();
	if (idx == len)
	{
		return true;
	}

	if (i < rSize && j < cSize && i >= 0 && j >= 0 && board[i][j] == word[idx])
	{
		idx++;
		char ch = board[i][j];
		board[i][j] = '#';
		bool below = findword(board, i + 1, j, word, idx);
	
		bool above = findword(board, i - 1, j, word, idx);
		
		bool right = findword(board, i, j + 1, word, idx);
		
		bool left = findword(board, i, j - 1, word, idx);

		if (!(below | above | right | left))
		{
			board[i][j] = ch;
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool exist(vector<vector<char> > &board, string word)
{
	int rSize = board.size();
	int cSize = board[0].size();
	int len = word.length();
	bool ret = false;
	for (int i = 0; i < rSize; i++)
	{
		for (int j = 0; j < cSize; j++)
		{
			if (board[i][j] == word[0])
			{
				vector<vector<char> > tmp(board);
				ret = findword(tmp, i, j, word, 0);
				if (ret)//必须的，因为只能上下左右，所以有可能第一个起点能够有路径与word一致
					//但是第二个起点可能没有路径与word一致
					/*Input:
					  ["abc","aed","afg"], "abcdefg"



					  Output:
					  false


					  Expected:
					  true
						*/
				{
					return ret;
				}
			}
		}
	}
	
	return ret;
}

int main()
{
	vector<vector<char> > board(1, vector<char>(2, 'a'));
	string s = "aaa";
	cout << exist(board, s) << endl;
	return 0;
}