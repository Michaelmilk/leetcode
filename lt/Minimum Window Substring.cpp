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

			//���v1[S[i]]��ǰֵΪ0����ô����v1[S[i]]--��v1[S[i]]��С��0
			//���Ե�v1[S[i]]�Ѿ�Ϊ��ʱ��tlen��������������Ҳ����tlen����������Ϊ��
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
			if (count1[S[end]] >= 0)//��Ϊ��Щ�ַ�T��ֻ��һ������S�п����ж����ѭ�����ڶ�����ͬ�ַ�ʱ��count�Ͳ���Ҫ����
				count--;
		}

		if (count == 0)//count=0��ÿ��ѭ����Ҫ���һ�ε�ǰ�ַ��Ƿ������ַ���ͬ
		{
			//S��T���ַ��ڶ��γ���ʱ������c1����Ӧ��ֵ����-1��
			//s���ٴγ�����S[start]��ͬ���ַ�ʱ����ʼ�±�start��ֵ
			//����Ϊǰ��û���ٴγ��ֵ��ַ���s�е��±�
			//����s:dadobecodebanc  t:bca  ��һ��startΪ1��endΪ6
			//�ڶ���count1[S[start]] < 0��end��ֵΪ11������c1['b'] = -1;
			//�������ǿ���ȷ��b���������Σ����Ե�һ��b���Բ�������㣬
			//��һ��ƥ�䴮����ʵ�±��ڵ�һ��b���棬��ʵ�������ַ�c��
			while (true)//�ҵ���S�У�T���ַ����ֵ���λ��
			{
				if (count2[S[start]] > 0)//˵��T�д���S[start]����ַ�����Ҫ��ѭ���м��start�±���ָ��S�е��ַ��Ƿ������T�У�
				{
					if (count1[S[start]] < 0)//С��0˵����ǰ�ַ��������S�е����ַ���T�е�ĳ���ַ���һ����˵��������һ���ַ��ظ���
						count1[S[start]]++;
					else
						break;
				}
				start++;//���ڵ�ǰ�ַ������ַ�һ�����������±����������һ������Ϊ�µ�Ԫ�ؿ��Դ������ַ�
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