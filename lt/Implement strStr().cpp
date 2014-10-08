#include <iostream>
#include <string>

using namespace std;


/*
char *strStr(char *haystack, char *needle)
{
	string s = haystack;
	
	int pos = s.find(needle);

	if (string::npos == pos)
	{
		return NULL;
	}
	return haystack + pos;
}*/

void get_nextval(const char *T, int next[])
{

	// 求模式串T的next函数值并存入数组 next。

	int j = 0, k = -1;

	next[0] = -1;

	while (T[j/*+1*/] != '\0')

	{

		if (k == -1 || T[j] == T[k])

		{

			++j; ++k;

			if (T[j] != T[k])

				next[j] = k;

			else

				next[j] = next[k];

		}// if

		else

			k = next[k];

	}// while

	////这里是我加的显示部分

	// 	 for(int  i=0;i<j;i++)
	// 
	// 	{
	// 
	// 	     cout<<next[i];
	// 
	// 	}
	// 
	// 	cout<<endl;

}// get_nextval　


char *strStr(char *Text, char *Pattern)
{
	if (Pattern[0] == '\0' && Text[0] == '\0')
		return "";

	//if (Pattern[0] == '\0' || Text[0] == '\0')// 

	//	return NULL;//空指针或空串，返回-1。


	int len = 0;

	const char * c = Pattern;

	while (*c++ != '\0')//移动指针比移动下标快。

	{

		++len;//字符串长度。

	}

	int *next = new int[len + 1];

	get_nextval(Pattern, next);//求Pattern的next函数值



	int index = 0, i = 0, j = 0;

	while (Text[i] != '\0'  && Pattern[j] != '\0')

	{

		if (Text[i] == Pattern[j])

		{

			++i;// 继续比较后继字符

			++j;

		}

		else

		{

			index += j - next[j];//当前字符如果不匹配，那么肯定从下一个位置进行匹配

			if (next[j] != -1)

				j = next[j];// 模式串向右移动

			else//next[j] == -1，S[N+1]和P[J]进行匹配

			{

				j = 0;

				++i;

			}

		}

	}//while



	delete[]next;

	if (Pattern[j] == '\0')

		return Text + index;// 匹配成功

	else

		return NULL;
}

int main()
{
	char* text = "";//"bababCabCadcaabcaababcbaaaabaaacababcaabc";

	char* pattern = "";//"ababCa";//"abCabCad";

	cout << strStr(text, pattern) << endl;		

	cout << "-------------------" << endl;

	cout << text << endl;
	return 0;
}