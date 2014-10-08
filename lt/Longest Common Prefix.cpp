#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
	int size = strs.size();
	if (!size)
	{
		return "";
	}
	
	int count = strs[0].size();//��Ϊ���ֻ��һ���ַ�������ô�Ϳ�����������ַ���
	int j = 0;
	for (int i = 1; i < size; i++)
	{
		int len = strs[i].size();
		for (j = 0; j < len; j++)
		{
			if (j > len || strs[0][j] != strs[i][j])
			{
				break;
			}
			
		}
		count = count > j ? j : count;//����䲻�ܷŻ���for�У��������ȫ��ƥ�䣬�ұ�strs[0]�̣���ô�ͻ����strs[0]
	}	

	return strs[0].substr(0, count);
}

int main()
{
	vector<string> s;
	s.push_back("aadfgfgh");
	s.push_back("aadfgfgh");
	s.push_back("aswfet");
	s.push_back("attrytrooiuiu");
	s.push_back("apppe");

	cout << longestCommonPrefix(s) << endl;
	return 0;
}