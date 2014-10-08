#include <iostream>
#include <vector>

using namespace std;

void solve(int idx, int i, int j, bool &ans, string word, 
	vector<vector<int> > &mark, vector<vector<char> > &board)
{
	if (idx == word.length())
	{
		ans = true;
		return;
	}

	if (i < (board.size() - 1) && !mark[i + 1][j] && board[i + 1][j] == word[idx])
	{
		mark[i + 1][j] = 1;
		solve(idx + 1, i + 1, j, ans, word, mark, board);
		if (ans)
		{
			return;
		}
		mark[i + 1][j] = 0;
	}

	if (i > 0 && !mark[i - 1][j] && board[i - 1][j] == word[idx])
	{
		mark[i - 1][j] = 1;
		solve(idx + 1, i - 1, j, ans, word, mark, board);
		if (ans)
		{
			return;
		}
		mark[i - 1][j] = 0;
	}
		

	if (j < (board[0].size() - 1) && !mark[i][j + 1]  && board[i][j + 1] == word[idx])
	{
		mark[i][j + 1] = 1;
		solve(idx + 1, i, j + 1, ans, word, mark, board);
		if (ans)
		{
			return;
		}
		mark[i][j + 1] = 0;
	}

	if (j > 0 && !mark[i][j - 1] && board[i][j - 1] == word[idx])
	{
		mark[i][j - 1] = 1;
		solve(idx + 1, i, j - 1, ans, word, mark, board);
		if (ans)
		{
			return;
		}
		mark[i][j - 1] = 0;
	}
}

bool exist(vector<vector<char> > &board, string word)
{
	bool ans = false;
	int rSize = board.size();
	if (0 == rSize && word.empty())
	{
		return true;
	}
	int cSize = board[0].size();
	vector<vector<int> > mark(rSize, vector<int>(cSize, 0));
	for (int i = 0; i < rSize; i++)
	{
		for (int j = 0; j < cSize; j++)
		{
			if (board[i][j] == word[0])
			{
				mark[i][j] = 1;
				solve(1, i, j, ans, word, mark, board);
			}
			mark[i][j] = 0;
		}
	}
	
	return ans;
}

int main()
{
	vector<char> v1 = { 'A','B','C','E' };
	vector<char> v2 = { 'S', 'F', 'C', 'S' };
	vector<char> v3 = { 'A','D','E','E' };

	vector<vector<char> > b;
	b.push_back(v1);
	b.push_back(v2);
	b.push_back(v3);

	cout << exist(b, "ABCCEE") << endl;
	return 0;
}