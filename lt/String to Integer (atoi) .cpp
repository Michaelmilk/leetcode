#include<iostream>

using namespace std;

/*
int atoi2(const char *str) {
	long long sum = 0;
	int ret = 0;
	int i = 0;
	int flag = 1;
	bool c = true;

	while (NULL != str[i])
	{
		if (str[i] == '-' && c)
		{
			flag = -1;
			if ('0' > str[i + 1] || '9' < str[i + 1])
			{
				break;
			}
		}
		else if (str[i] == '+' && c)
		{
			if ('0' > str[i + 1] || '9' < str[i + 1])
			{
				break;
			}
		}
		else if (('9' >= str[i] && '0' <= str[i]))
		{
			sum = sum * 10 + (str[i] - 48);
			c = false;
		}
		else if (!c)
		{
			break;
		}
		else if (' ' != str[i])
		{
		break;
		}
		i++;
	}

	if (1 == flag)
	{
		ret = INT_MAX < sum ? INT_MAX : sum;
	}
	else
	{
		ret = INT_MIN > (flag * sum) ? INT_MIN : sum;
	}
	return flag * ret;
}
*/

__int64 atoi2(const char *str) {
	//long long sum = 0;
	__int64 sum = 0;
	__int64 ret = 0;
	int i = 0;
	int flag = 1;
	bool c = true;
	bool st = false;

	while (NULL != str[i])
	{
		
		if (str[i] == '-' && c)
		{
			flag = -1;
			if ('0' > str[i + 1] || '9' < str[i + 1])
			{
				break;
			}
		}
		else if (str[i] == '+' && c)
		{
			if ('0' > str[i + 1] || '9' < str[i + 1])
			{
				break;
			}
		}
		else if (('9' >= str[i] && '0' <= str[i]))
		{
			sum = sum * 10 + (str[i] - 48);
			c = false;
		}
		else if (!c)//数字后面出现非数字字符的情况
		{
			break;
		}
		else if (' ' != str[i])//数字之前出现非空格字符的情况
		{
			break;
		}
		
		i++;
	}

	if (1 == flag)
	{
		ret = INT_MAX < sum ? INT_MAX : sum;
	}
	else
	{
		ret = INT_MIN > (flag * sum) ? INT_MIN : sum;
	}
	return flag * ret;
}

int main()
{
	char *s = "++12";// "   - 321"; //"-2147483649";//"  -0012a42";//"999999999999999999";// "   -3423wewe56"  "   3423we-we56"
	cout << atoi2(s) << endl;

	//cout << 80 % 1 << endl;
	return 0;
}