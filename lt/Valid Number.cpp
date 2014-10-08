#include <iostream>
#include <cctype>

using namespace std;

bool isNumber(const char *s)
{
	int len = 0;
	int countDot = 0;
	int countE = 0;
	int firstCh = 0;

	while (s[len] == ' ')
	{
		len++;
		continue;
	}

	firstCh = len;

	if (s[len] == '\0')
	{
		return false;
	}

	while (s[len] != '\0')
	{
		if (countDot > 1 || countE > 1)
		{
			return false;
		}

		if (!isdigit(s[len]))
		{
			//if ((0 == len || 1 == len) && (s[len] == '.' || s[len] =='e'))//".1":true;"e9":false
			/*if (0 == len&& s[len] == '.')//" .9":true
			{
			if(!isdigit(s[len + 1]))//" ."：false;". "：false;
			{
			return false;
			}
			countDot++;
			len++;
			continue;
			}
			else if(s[len] == '.')//" 9."：false;*/
			if ((len == firstCh && (s[len] == '-' || s[len] == '+')) ||
				((s[len] == '-' || s[len] == '+') && s[len - 1] == 'e'))
			{
				if (!isdigit(s[len + 1]) && s[len + 1] != '.')//"46e+":false;"+.8":true;" 005047e+6":true
				{
					return false;
				}
				len++;
				continue;
			}
			else if (s[len] == '.')
			{
				if (len == firstCh && !isdigit(s[len + 1]))//"."：false;
				{
					return false;
				}
				if ((!isdigit(s[len - 1]) && !(s[len - 1] == '-' || s[len - 1] == '+')) &&
					!isdigit(s[len + 1]))//" ."：false;"3.":true;" .9":true;"-.":false
				{
					return false;
				}
				if ((!isdigit(s[len - 1]) && (s[len - 1] == '-' || s[len - 1] == '+')) &&
					!isdigit(s[len + 1]))//"-.":false
				{
					return false;
				}

				if (s[len + 1] == 'e' && firstCh == len)//".e1":false
				{
					return false;
				}
				if (countE > 0)
				{
					return false;
				}
				countDot++;
				len++;
				continue;
			}
			else if (s[len] == 'e')//"0e":false;"    5e2":true;"0e1":true;"e9":false;"-e58 ":false;"46.e3":true
			{
				int t = len - 1;
				int count = 0;
				if (s[t] == '.')//"32.e-80123":true
				{
					t--;
				}
				while (isdigit(s[t]))
				{
					if (t < 0)//"4e+1831773":true
					{
						break;
					}
					count += s[t] - '0';
					t--;

				}
				if (count == 0 && !isdigit(s[len + 1]))//"0e1":true;"0e":false;" 005047e+6":true;"32.e-80123":true
				{
					return false;
				}
				if (firstCh == len /*"e9":false;*/ || (!isdigit(s[len - 1]) && s[len - 1] != '.') ||
					(!isdigit(s[len + 1]) && !(s[len + 1] == '-' || s[len + 1] == '+')) //" 005047e+6":true;"+10e+46749":true
					)
				{
					return false;
				}
				countE++;
				len++;
				continue;
			}
			else if (s[len] == ' ')
			{
				int i = len + 1;
				while (s[i] != '\0')//如果数字后面出现空格且空格之后全部是空格则成立
				{
					if (s[i] != ' ')
					{
						return false;
					}
					i++;
				}
				return true;
			}
			else
			{
				return false;
			}
		}

		len++;
	}

	if (countDot > 1 || countE > 1)
	{
		return false;
	}

	return true;
}

int main()
{
	cout << isNumber("10e") << endl;
	return 0;
}