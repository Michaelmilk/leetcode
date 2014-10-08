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

	for (int i = 0; i < nRows && i < size; i++)//i < size�Է����������ַ����ĳ���
	{
		int index = i;
		ret += s[index];

		for (int j = 1; j < size; j++)//�е��±���0��ʼ����Ϊ��һ�е�ֵ�Ѿ�ȷ��������ֱ�Ӵӵڶ��п�ʼ���±�Ϊ1��
		{
			if (0 == i || nRows - 1 == i)//��һ�к����һ��ÿ���ַ����2*nrows - 2
			{
				index += 2 * nRows - 2;
			}
			else
			{
				if (j & 0x1)//�����У����±굽��һ���±�����ֵ��������������i����������еĵ�ĸ�������2 * (nRows - 1 - i)��
				{
					index += 2 * (nRows - 1 - i);
				}
				else
				{
					index += 2 * i;//ż���У�����±굽��һ���±�����ֵ��ʵ��������������i����������еĵ�ĸ�������2 * i

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

		for (int lr = nRows - 2; lr > 0 && i < size; i++, lr--)//���ڵ�һ�к����һ���м�Ĳ���
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