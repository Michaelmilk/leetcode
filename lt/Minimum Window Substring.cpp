#include <iostream>
#include <string>
#include <vector>

using namespace std;


string minWindow(string S, string T) 
{
	int sLen = S.length();
	int tLen = T.length();
	if (tLen > sLen || 0 == sLen || 0 ==tLen)
	{
		return "";
	}

	vector<int> v1(256, 0);
	vector<int> v2(256, 0);
	for (int i = 0; i < tLen; i++)
	{
		v1[T[i]]++;
		v2[T[i]]++;
	}

	int start = 0;
	int minSize = INT_MAX;
	int minStart = 0;
	
	for (int i = 0; i < sLen; i++)
	{
		if (v2[S[i]] > 0)
		{
			v1[S[i]]--;

			//如果v1[S[i]]当前值为0，那么经过v1[S[i]]--后，v1[S[i]]必小于0
			//所以当v1[S[i]]已经为零时，tlen不会再做减法，也就是tlen见到最后绝对为零
			if (v1[S[i]] >= 0)
			{
				tLen--;
			}
		}

		if (0 == tLen)
		{
			while (true)
			{
				if (v2[S[start]] > 0)
				{
					if (v1[S[start]] < 0)
					{
						v1[S[start]]++;
					}
					else
					{
						break;
					}
				}
				start++;
			}

			if (minSize > i - start + 1)
			{
				minSize = i - start + 1;
				minStart = start;
			}
		}

	}

	if (minSize == INT_MAX)
	{
		return "";
	}

	string ans(S, minStart, minSize);
	return  ans;
}


/*
int count1[256];
int count2[256];

string minWindow(string S, string T) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (T.size() == 0 || S.size() == 0)
		return "";

	memset(count1, 0, sizeof(count1));
	memset(count2, 0, sizeof(count2));

	for (int i = 0; i < T.size(); i++)
	{
		count1[T[i]]++;
		count2[T[i]]++;
	}

	int count = T.size();

	int start = 0;
	int minSize = INT_MAX;
	int minStart;
	for (int end = 0; end < S.size(); end++)
	{
		if (count2[S[end]] > 0)
		{
			count1[S[end]]--;
			if (count1[S[end]] >= 0)//因为有些字符T中只有一个，而S中可能有多个，循环到第二个相同字符时，count就不需要减了
				count--;
		}

		if (count == 0)//count=0后，每次循环都要检查一次当前字符是否与首字符相同
		{
			//S中T的字符第二次出现时，数组c1中相应的值会变成-1，
			//s中再次出现于S[start]相同的字符时，则开始下标start的值
			//更新为前面没有再次出现的字符在s中的下标
			//比如s:dadobecodebanc  t:bca  第一次start为1，end为6
			//第二次count1[S[start]] < 0的end的值为11，由于c1['b'] = -1;
			//所以我们可以确定b出现了两次，所以第一个b绝对不会是起点，
			//下一个匹配串的其实下标在第一个b后面，事实上是在字符c处
			while (true)//找到在S中，T中字符出现的首位置
			{
				if (count2[S[start]] > 0)//说明T中存在S[start]这个字符（主要在循环中检测start下标所指的S中的字符是否出现在T中）
				{
					if (count1[S[start]] < 0)//小于0说明当前字符与出现在S中的首字符（T中的某个字符）一样，说明至少有一个字符重复了
						count1[S[start]]++;
					else
						break;
				}
				start++;//由于当前字符与首字符一样，所以首下标可以往后移一个，以为新的元素可以代替首字符
			}

			if (minSize > end - start + 1)
			{
				minSize = end - start + 1;
				minStart = start;
			}
		}
	}

	if (minSize == INT_MAX)
		return "";

	string ret(S, minStart, minSize);

	return ret;
}
*/

int main()
{
	//cout << minWindow("dadobecodebanc", "bca") << endl;
	cout << minWindow("a", "b") << endl;;
	return 0;
}