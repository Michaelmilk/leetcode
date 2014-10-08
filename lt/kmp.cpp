#include <iostream>
#include <string>
using namespace std;


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


int KMP(const char *Text, const char* Pattern) //const ��ʾ�����ڲ�����ı����������ֵ��

{

	if (!Text || !Pattern || Pattern[0] == '\0' || Text[0] == '\0')// 

		return -1;//��ָ���մ�������-1��

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

		return index;// ƥ��ɹ�

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