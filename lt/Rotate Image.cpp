#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/*
void rotate(vector<vector<int> > &matrix)
{
	int size = matrix.size();

	ostream_iterator<int> ofile(cout, " ");

	//���Խ��߻���
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[size - 1 - j][size - 1 - i];
			matrix[size - 1 - j][size - 1 - i] = tmp;
		}
	}

	for (int i = 0; i < matrix.size(); i++)
	{
		copy(matrix[i].begin(), matrix[i].end(), ofile);
		cout << endl;
	}
	cout << "----------------------------------" << endl;
	//ˮƽ���߻���
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[size - 1 - i][j];
			matrix[size - 1 - i][j] = tmp;
		}
	}
	
}
*/

void rotate(vector<vector<int> > &matrix)
{
// 	int n = matrix.size();
// 	for (int i = 0; i < n / 2; ++i) 
// 	{
// 		for (int j = 0; j < (n + 1) / 2; ++j) 
// 		{
// 			int temp = matrix[j][n - i - 1];
// 			matrix[j][n - i - 1] = matrix[i][j];
// 			matrix[i][j] = matrix[n - j - 1][i];
// 			matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
// 			matrix[n - i - 1][n - j - 1] = temp;
// 		}	
// 	}

	int n = matrix.size();
	for (int i = 0; i < (n + 1) / 2; ++i)//ѭ���˳�������ѡ����ϸ�۲�ᷢ�ֽ��������ֿ������һ�������Σ�ֻҪѡ����Ҫ����λ�õ�4�����е�һ����
	{
		for (int j = 0; j < n / 2; ++j)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = temp;
		}
	}

}

int main()
{
	vector<vector<int> > v = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };

	ostream_iterator<int> ofile(cout, " ");

	rotate(v);

	for (int i = 0; i < v.size(); i++)
		{
			copy(v[i].begin(), v[i].end(), ofile);
			cout << endl;
		}
	return 0;
}