#include <iostream>

using namespace std;

bool isMatch(const char *s, const char *p) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (*p == '\0') {
		return *s == '\0';
	}

	/*如果当前字符的下一个字符是“*”，那么（isMatch(s, p + 2)为TRUE表示s与p+2相匹配）
	1."*"前面的字符与S是不匹配的，那么直接跳过当前字符和"*",isMatch(s, p + 2);
	2."*"前面的字符为"."或者与s相匹配,那么先继续匹配p的下下个字符（因为下一个字符为"*"），
		如果不匹配，那么取s的下一个字符进行比较"
	*/

	if (*(p + 1) == '*') 
	{
		while (*s != '\0' && (*s == *p || *p == '.'))//循环是为了匹配多个重复字符的情况，或者长度不匹配的情况（s=aaa，p=a*a）
		{
			if (isMatch(s, p + 2)) {
				return true;
			}
			s++;
		}
		return isMatch(s, p + 2);
	}
	else //如果当前字符的下一个字符是“*”，那么则s和p一一比较
	{
		if (*s != '\0' && (*s == *p || *p == '.')) {
			return isMatch(s + 1, p + 1);
		}
	}

	return false;
}


int main()
{
	cout << isMatch("aba", ".*a") << endl;;
	return 0;
}