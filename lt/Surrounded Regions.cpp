#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
void setMark(int i, int j, vector<vector<char>> &board)
{
	if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size())
	{
		return;
	}

	if (board[i][j] == 'O')
	{
		board[i][j] = '1';
		setMark(i + 1, j, board);
		setMark(i - 1, j, board);
		setMark(i, j + 1, board);
		setMark(i, j - 1, board);
	}
}

void solve(vector<vector<char>> &board)
{
	int row = board.size();
	if (row <= 2)
	{
		return;
	}

	int col = board[0].size();
	if (col <= 2)
	{
		return;
	}

	//首先把与边界的O相连的O全部标记出来，这些相连的O块是不被X包围的
	//然后再将没有设置标志的O全部设置为X，这些事全部被X包围的
	for (int i = 0; i < row; i++)//left
	{
		if (board[i][0] == 'O')
		{
			setMark(i, 0, board);
		}
	}

	for (int i = 1; i < col; i++)//buttom
	{
		if (board[row - 1][i] == 'O')
		{
			setMark(row - 1, i, board);
		}
	}

	for (int i = 1; i < row; i++)//right
	{
		if (board[i][col - 1] == 'O')
		{
			setMark(i, col - 1, board);
		}
	}

	for (int i = 0; i < col; i++)//top
	{
		if (board[0][i] == 'O')
		{
			setMark(0, i, board);
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == '1')
			{
				board[i][j] = 'O';
			}
			else if (board[i][j] == 'O')//必须else if不然之前设置的O全部变成X
			{
				board[i][j] = 'X';
			}
		}
	}
}*/

queue<int> q;  
int m, n;  

 void add(int x, int y, vector<vector<char>> &board) {
	 if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
		 board[x][y] = 'Z';
		 q.push(x * n + y);
	 }
 }

 void traversal(int x, int y, vector<vector<char>> &board) {
	 add(x, y, board);
	 while (!q.empty()) {
		 int p = q.front();
		 q.pop();
		 int px = p / n, py = p % n;
		 add(px - 1, py, board);
		 add(px + 1, py, board);
		 add(px, py - 1, board);
		 add(px, py + 1, board);
	 }
 }

 void solve(vector<vector<char>> &board) {
	 // Start typing your C/C++ solution below  
	 // DO NOT write int main() function  
	 if (board.empty() || board.size() == 0 || board[0].size() == 0) {
		 return;
	 }
	 m = board.size(), n = board[0].size();
	 for (int i = 0; i < n; i++) {
		 traversal(0, i, board);
		 traversal(m - 1, i, board);
	 }
	 for (int i = 0; i < m; i++) {
		 traversal(i, 0, board);
		 traversal(i, n - 1, board);
	 }
	 for (int i = 0; i < m; i++) {
		 for (int j = 0; j < n; j++) {
			 board[i][j] = board[i][j] == 'Z' ? 'O' : 'X';
		 }
	 }
}  


int main()
{
	//vector<char> v = {"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" };
	vector<char> v;
	for (int i = 0; i < 251; i++)
	{
		v.push_back('O');
	}
	vector<vector<char>> board;
	board.push_back(v);
	solve(board);
	return 0;
}