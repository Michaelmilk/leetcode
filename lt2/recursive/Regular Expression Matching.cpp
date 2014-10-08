#include <iostream>

using namespace std;

/*
bool isMatch(const char *s, const char *p)
{
	const char *ss = NULL;
	bool flag = false;
	while (*s != '\0')
	{
		cout << *s << endl;
		cout << *p << endl;
		if (*s == *p || *p == '.')
		{
			s++;
			if (flag)
			{
				p = p + 2;
				flag = false;
			}
			else
			{
				p++;
			}
			
		}
		else if (*p == '*')
		{
			ss = p;
			flag = true;
			p--;
		}
		else if (*s != *p && *(++p) == '*')//ignore the letter
		{
			p++;
		}
		else if (*s != *p && ss != NULL)
		{
			p = ss - 1;
		}
		else
		{
			return false;
		}
	}

	while (*p != '\0')
	{
		if (*p != '*' && *(p + 1) != '*')
		{
			return false;
		}
		p++;
	}

	return true;
}
*/

bool isMatch(const char *s, const char *p)
{
	if (*p == '\0')
	{
		return *s == '\0';
	}
	
	if (*(p + 1) == '*')
	{
		while (*s != '\0' && (*s == *p && *p == '.'))
		{
			if (isMatch(s, p + 2))//直接与‘*’后面的字符进行匹配（abc：a*abc）
			{
				return true;
			}
			s++;//一直与‘*’前一个字符进行匹配（aaaaa：a*）直到*s与‘*’前一个字符不匹配，则跳出循环
		}
		return isMatch(s, p + 2);//跳出循环后，*s与‘*’后面的字符串进行匹配（aaaab：a*b）
	}
	else
	{
		if (*s != '\0' && (*s == *p || *p == '.'))
		{
			return isMatch(s + 1, p + 1);
		}
		else
		{
			return false;
		}
	}

	//return false;
}

int main()
{
	cout << isMatch("baccbbcbcacacbbc", "c*.*b*c*ba*b*b*.a*") << endl;
	/*
	char *s = "";
	cout << *s << endl;
	cout << "-----------" << endl;
	cout << s << endl;
	cout << "-----------" << endl;
	while (s)
	{
		cout << "hahah" << endl;
	}
	*/
	return 0;
}