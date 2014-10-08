#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;


#define N  4
//int col[N + 1];
vector<string> tmp;
vector<vector<string> > ret;
vector<int> col;

//输出结果
void Output()
{
	for (int i = 1; i <= N; i++)
	{
		string s = "";
		for (int j = 1; j <= N; j++)
		{
			if (j == col[i])
			{
				s += "Q";
				printf("Q");
			}
			else
			{
				s += ".";
				printf(".");
			}
		}
		s += "\n";
		tmp.push_back(s);
		printf("\n");
	}
	//tmp.push_back("\n");
	ret.push_back(tmp);
	tmp.clear();
	printf("\n");
}
//求解函数
void Queen(int i, int n)
{
	if (i > n)
		Output();
	else
	{
		for (int j = 1; j <= n; ++j)
		{
			int k = 1;
			col[i] = j;
			while (k < i)
			{
				if ((col[k] - col[i])*(fabs((double)(col[k] - col[i])) - fabs((double)(k - i))) != 0)
				{
					k++;
					if (k == i)
						Queen(i + 1, n);
				}
				else
				{
					break;
				}
			}
		}
	}
}
int main()
{
	printf("the answer is:\n");
	col.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		col[1] = i; //设置第一行的第i列
		Queen(2, N);
	}

	cout << "---------------------------------------------------------" << endl;
	int size = ret.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ret[i][j];
		}
		cout << endl;
	}
	return  0;
}