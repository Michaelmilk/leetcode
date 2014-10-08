#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
string convert(string s, int nRows)
{
	string ret;
	int size = s.size();

	if (0 == size || 1 == nRows)
	{
		return s;
	}

	for (int i = 0; i < nRows && i < size; i++)//i < size以防行数大于字符串的长度
	{
		int index = i;
		ret += s[index];

		for (int j = 1; j < size; j++)//列的下标以0开始，因为第一列的值已经确定，所以直接从第二列开始，下表为1。
		{
			if (0 == i || nRows - 1 == i)//第一行和最后一行每个字符相隔2*nrows - 2
			{
				index += 2 * nRows - 2;
			}
			else
			{
				if (j & 0x1)//奇数列，个下标到下一个下标相差的值是它们所处的行i下面的所有行的点的个数，即2 * (nRows - 1 - i)。
				{
					index += 2 * (nRows - 1 - i);
				}
				else
				{
					index += 2 * i;//偶数列，这个下标到下一个下标相差的值其实是它们所处的行i上面的所有行的点的个数，即2 * i

				}
			}

			if (index < size)
			{
				ret += s[index];
			}
		}
	}
	
	return ret;
}
*/

string convert(string s, int nRows)
{
	int size = s.size();
	vector<vector<char> > ret;

	int i = 0;
	for (i = 0; i < nRows; i++)
	{
		vector<char> temp;
		ret.push_back(temp);
	}

	i = 0;
	while (i < size)
	{
		for (int r = 0; r < nRows && i < size; i++, r++)
		{
			ret[r].push_back(s[i]);
		}

		for (int lr = nRows - 2; lr > 0 && i < size; i++, lr--)//介于第一行和最后一行中间的部分
		{
			ret[lr].push_back(s[i]);
		}
	}

	string str = "";

	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < (ret[i].size()); j++)
		{
			str += ret[i][j];
		}
	}

	return str;
}

int main()
{
	string str = "PAYPALISHIRING";
	cout << convert(str, 3) << endl;
	return 0;
}