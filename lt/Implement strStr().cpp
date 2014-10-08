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

	// ��ģʽ��T��next����ֵ���������� next��

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

	////�������Ҽӵ���ʾ����

	// 	 for(int  i=0;i<j;i++)
	// 
	// 	{
	// 
	// 	     cout<<next[i];
	// 
	// 	}
	// 
	// 	cout<<endl;

}// get_nextval��


char *strStr(char *Text, char *Pattern)
{
	if (Pattern[0] == '\0' && Text[0] == '\0')
		return "";

	//if (Pattern[0] == '\0' || Text[0] == '\0')// 

	//	return NULL;//��ָ���մ�������-1��


	int len = 0;

	const char * c = Pattern;

	while (*c++ != '\0')//�ƶ�ָ����ƶ��±�졣

	{

		++len;//�ַ������ȡ�

	}

	int *next = new int[len + 1];

	get_nextval(Pattern, next);//��Pattern��next����ֵ



	int index = 0, i = 0, j = 0;

	while (Text[i] != '\0'  && Pattern[j] != '\0')

	{

		if (Text[i] == Pattern[j])

		{

			++i;// �����ȽϺ���ַ�

			++j;

		}

		else

		{

			index += j - next[j];//��ǰ�ַ������ƥ�䣬��ô�϶�����һ��λ�ý���ƥ��

			if (next[j] != -1)

				j = next[j];// ģʽ�������ƶ�

			else//next[j] == -1��S[N+1]��P[J]����ƥ��

			{

				j = 0;

				++i;

			}

		}

	}//while



	delete[]next;

	if (Pattern[j] == '\0')

		return Text + index;// ƥ��ɹ�

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