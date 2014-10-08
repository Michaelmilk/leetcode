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
		//ȷ��ĳ�п����е�����word��Ŀ
		for (ed = st; ed < size; ed++)
		{
			int wSize = words[ed].size();
			if (len + (ed - st) + wSize > L)
			{
				break;
			}
			len += wSize;
		}

		ed = ed < st ? st : --ed;//ĳ�����һ�����ʵ��±�(���ֻ��һ��������ô����st��
		int count = ed - st;//�ܹ�����ո�ĵط���Ҳ���ǵ��ʵļ����
		if (st == ed)
		{
			string line = words[st];
			line.append(L - line.length(), ' ');
			rs.push_back(line);
		} 
		else
		{
			int spaceAvg = (L - len) / count;//���ʼ�ƽ���ֵ��Ŀո���
			int rest = L - len - spaceAvg * count;//ƽ�ַ����ʣ�µĿո���
			if (ed == size - 1)
			{
				spaceAvg = 1;
				rest = 0;
			}

			string line = words[st];
			for (int i = st + 1; i <= ed; i++)//��������յĺϲ����Ӵ���Ϊһ��
			{
				int space = spaceAvg;
				if (rest > 0)//�Ѷ�����Ŀո�ƽ��������������ҵĿո���
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
			if (ed == size - 1) //��Ϊ֮ǰ��spaceAvg = 1;rest = 0;�ֱ����������
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