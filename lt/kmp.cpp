#include <iostream>
#include <string>
using namespace std;


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


int KMP(const char *Text, const char* Pattern) //const 表示函数内部不会改变这个参数的值。

{

	if (!Text || !Pattern || Pattern[0] == '\0' || Text[0] == '\0')// 

		return -1;//空指针或空串，返回-1。

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

		return index;// 匹配成功

	else

		return -1;

}

int main()//abCabCad 

{

	char* text = "";//"bababCabCadcaabcaababcbaaaabaaacababcaabc";

	char*pattern = "";//"ababCa";//"abCabCad";

	//getNext(pattern,n); 

	//get_nextval(pattern,n); 

	cout << KMP(text, pattern) << endl;

	return 0;

}

/*
int main()
{
	int i, j, k;
	string needle = "abcabcad";
	int needlen = needle.size();
	int* fail = new int[needlen];
	memset(fail, -1, needlen * sizeof(int));    // strlen(fail)  

	for (i = 1; i < needlen; ++i) {
		for (k = fail[i - 1]; k >= 0 && needle[i] != needle[k + 1]; k = fail[k]);
		if (needle[k + 1] == needle[i])
			fail[i] = k + 1;
	}
	
	for (int i = 0; i < needlen; i++)
	{
		cout << fail[i] << endl;
	}

	get_nextval(needle.c_str(), fail);
	return 0;
}*/