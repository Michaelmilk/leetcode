#include <iostream>
using namespace std;


// bool isMatch(const char *s, const char *p)
// {
// 	if (*p == '\0')
// 	{
// 		return *s == '\0';
// 	}
// 
// 	if (*s != '\0' && *p == *s)
// 	{
// 		return isMatch(s + 1, p + 1);
// 	}
// 	else if (*s != '\0' && *p == '?')
// 	{
// 		
// 		return isMatch(s + 1, p + 1);
// 	}
// 	else if (*p == '*')
// 	{
// 		while (*s != '\0' && *(p + 1) != '*')
// 		{
// 			if (isMatch(s + 1, p + 1))
// 			{
// 				return true;
// 			}
// 			s++;
// 		}
// 		return isMatch(s, p + 1);
// 	}
// 	else
// 		return false;
// 	
// }


bool isMatch(const char *s, const char *p) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (!s && !p) return true;

	const char *star_p = NULL, *star_s = NULL;

	while (*s)
	{
		if (*p == '?' || *p == *s)
		{
			++p, ++s;
		}
		else if (*p == '*')
		{
			//skip all continuous '*'
			while (*p == '*') ++p;

			if (!*p) return true; //if end with '*', its match.

			star_p = p; //store '*' pos for string and pattern
			star_s = s;
		}
		else if ((!*p || *p != *s) && star_p)
		{
			s = ++star_s; //skip non-match char of string, regard it matched in '*'
			p = star_p; //pattern backtrace to later char of '*'
		}
		else
			return false;
	}

	//check if later part of p are all '*'
	while (*p)
	{
		if (*p++ != '*')
			return false;
	}

	return true;
}



int main()
{
	char *s = "abbbaaaaaaaabbbabaaabbabbbaabaabbbbaabaabbabaabbabbaabbbaabaabbabaabaabbbbaabbbaabaaababbbbabaaababbaaa";// aaaaaaaabbbabaaabbabbbaabaabbbbaabaabbabaabbabbaabbbaabaabbabaabaabbbbaabbbaabaaababbbbabaaababbaaa";//"abba";// abbabbbbaaabbabbabaaabbababbbabbbabaaabaab";//"abbaabbbbaaaaabababbbaabbaabaababbaababaabbabbaabbbab";
	char *p = "ab**b*bb*ab**ab***b*abaa**b*a*aaa**bba*aa*a*abb*a*a";// *bb*ab**ab***b*abaa**b*a*aaa**bba*aa*a*abb*a*a";//"ab**ba";// *b**b***bba";// "***************bb***b**";
	cout << isMatch(s, p) << endl;
	return 0;
}