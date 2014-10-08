#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string> &words, int L)
{
	vector<string> rs;
	int size = words.size();
	if (0 == size || 0 == L)
	{
		rs = words;
		return rs;
	}

	int st = 0;
	int ed = 0;
	int len = 0;
	while (st < size)
	{
		len = 0;
		//确定某行可以有的最大的word数目
		for (ed = st; ed < size; ed++)
		{
			int wSize = words[ed].size();
			if (len + (ed - st) + wSize > L)
			{
				break;
			}
			len += wSize;
		}

		ed = ed < st ? st : --ed;//某行最后一个单词的下表(如果只有一个单词那么就是st）
		int count = ed - st;//能够插入空格的地方（也就是单词的间隔）
		if (st == ed)
		{
			string line = words[st];
			line.append(L - line.length(), ' ');
			rs.push_back(line);
		} 
		else
		{
			int spaceAvg = (L - len) / count;//单词间平均分到的空格数
			int rest = L - len - spaceAvg * count;//平局分配后剩下的空格数
			if (ed == size - 1)
			{
				spaceAvg = 1;
				rest = 0;
			}

			string line = words[st];
			for (int i = st + 1; i <= ed; i++)//将单词与空的合并成子串成为一行
			{
				int space = spaceAvg;
				if (rest > 0)//把多出来的空格平均分配给从左往右的空格中
				{
					space++;
					rest--;
				}
				line.append(space, ' ');
				line.append(words[i]);
			}
			/*Input:
			  ["What","must","be","shall","be."], 12

			  Output:
			  ["What must be","shall be."]
			  			  
			  Expected:
			  ["What must be","shall be.   "]
			*/
			if (ed == size - 1) //因为之前将spaceAvg = 1;rest = 0;分别进行了设置
			{
				line.append(L - len - ed + st, ' ');
			}
			rs.push_back(line);
		}
		st = ed + 1;
	}
	return rs;
}

int main()
{
	vector<string> v;
	v.push_back("a");
	v.push_back("b");
	v.push_back("c");
	v.push_back("d");
	v.push_back("e");
	fullJustify(v, 1);
	return 0;
}