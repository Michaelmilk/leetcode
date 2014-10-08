#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> ret;
int pos[4];

bool isValid(string s, int begin, int end)
{
	string field(s, begin, end - begin + 1);//end - begin + 1
	int size = field.size();
	if (1 == size)
	{
		return field >= "0" && field <= "9";
	}
	else if (2 == size)
	{
		return field >= "10" && field <= "99";
	}
	else if (3 == size)
	{
		return field >= "100" && field <= "255";
	}
	else
	{
		return false;
	}
}

void dfs(int curLevel, int maxLevel, string s, int startPos)
{
	int len = s.length();
	if (curLevel == maxLevel)
	{
		if (startPos == len)
		{
			string ans;
			int beg = 0;
			for (int i = 0; i < maxLevel; i++)
			{
				//string field(s, beg, pos[i] - beg + 1);//获取ip地址的每个字段
				string field(s, beg, pos[i] - beg);//获取ip地址的每个字段
				beg = pos[i];
				ans += (0 == i) ? field : "." + field;
			}
			ret.push_back(ans);
		}
		return;	
	}

	for (int i = startPos; i < len; i++)
	{
		if (isValid(s, startPos, i))
		{
			//pos[curLevel] = i;
			pos[curLevel] = i + 1;//字符串中ip每个字段的截至下标+1也就是下一个字段的开始位置的下标
			dfs(curLevel + 1, maxLevel, s, i + 1);
		}
	}

}

vector<string> restoreIpAddresses(string s)
{
	int curLevel = 0;
	int maxLevel = 4;
	int startPos = 0;
	dfs(curLevel, maxLevel, s, startPos);
	
	return ret;
}

int main()
{
	restoreIpAddresses("0000");
	return 0;
}