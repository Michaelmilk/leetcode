#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/*TLE
vector<string> ans;

//bool isExist(string s, unordered_set<string> &dict)
//{
//	if (dict.find(s) == dict.end())
//	{
//		return false;
//	}
//	return true;
//}

//void solve(int idx, string s, vector<string> tmp, int len, unordered_set<string> &dict)
//{
//	if (idx == len)
//	{
//		int size = tmp.size();
//		string str;
//		for (int i = 0; i < size; i++)
//		{
//			str += i == size - 1 ? tmp[i] : tmp[i] + " ";
//		}
//		ans.push_back(str);
//		return;
//	}
//
//	for (int i = idx; i < len; i++)
//	{
//		//string t(s.begin() + idx, s.begin() + i + 1);
//		string t = s.substr(idx, i - idx + 1);
//		if (isExist(t, dict))
//		{
//			tmp.push_back(t);
//			solve(i + 1, s, tmp, len, dict);
//			tmp.pop_back();
//		}
//	}
//}
void solve(int idx, string s, string tmpStr, int len, unordered_set<string> &dict)
{
	if (idx == len)
	{
		ans.push_back(tmpStr);
		return;
	}

	for (int i = idx; i < len; i++)
	{
		//string t(s.begin() + idx, s.begin() + i + 1);
		string t = s.substr(idx, i - idx + 1);
		if (dict.find(t) != dict.end())
		{
			string tt(tmpStr);
			tt += (i == len - 1) ? t : t + " ";
			solve(i + 1, s, tt, len, dict);
		}
	}
}


vector<string> wordBreak(string s, unordered_set<string> &dict)
{
	int len = s.length();
	if (dict.empty())
	{
		return ans;
	}

	solve(0, s, "", len, dict);

	return ans;
}
*/


void word(vector<string> &rs, string &tmp, string &s, vector<vector<int> > &tbl,
	unordered_set<string> &dict, int start = 0)
{
	if (start == s.length())
	{
		rs.push_back(tmp);
		return;
	}
	for (int i = 0; i < tbl[start].size(); i++)
	{
		string t = s.substr(start, tbl[start][i] - start + 1);
		if (!tmp.empty())
		{
			tmp.push_back(' ');
		}
		tmp.append(t);
		word(rs, tmp, s, tbl, dict, tbl[start][i] + 1);
		//����ǰ������Ӵ���Ҳ����tmp�е����һ���ִ�����tmp�����
		//�����Ӵ�֮���пո�ָ������Ը������һ���Ƿ�Ϊ�ո�������
		//back����ֻ�ǻ�ȡ���һ���ַ�����ΪҪɾ�����һ���Ӵ���
		//������whileѭ��
		while (!tmp.empty() && tmp.back() != ' ')
		{
			tmp.pop_back();//tmp.empty()
		}
		if (!tmp.empty())//���ո������Ȼ�󷽱���һ��ݹ�ɾ�����һ��Ԫ��
		{
			tmp.pop_back();
		}
	}
}

//�����ֵ����е��Ӵ������䣬tbl[i]={j}���������ֵ��ʾs�дӵ�i���ַ�����j���ַ����Ӵ���dict�С�
vector<vector<int> > genTable(string &s, unordered_set<string> &dict)
{
	int n = s.length();
	vector<vector<int> > tbl(n);
	for (int i = n - 1; i >= 0; i--)
	{
		if (dict.count(s.substr(i)))
		{
			tbl[i].push_back(n - 1);
		}	
	}
	for (int i = n - 2; i >= 0; i--)
	{
		if (!tbl[i + 1].empty())//if we can break i->n
		{
			for (int j = i, d = 1; j >= 0; j--, d++)//�ӵ�ǰ�±�������ǰȡ�Ӵ����鿴�Ƿ����ֵ���
			{
				if (dict.count(s.substr(j, d)))
				{
					tbl[j].push_back(i);
				}
			}
		}
	}
	return tbl;
}

vector<string> wordBreak(string s, unordered_set<string> &dict)
{
	vector<string> rs;
	string tmp;
	vector<vector<int> > tbl = genTable(s, dict);
	word(rs, tmp, s, tbl, dict);
	return rs;
}

int main()
{
	string s = "catsanddog";
	unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};

	vector<string> v = wordBreak(s, dict);

	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}