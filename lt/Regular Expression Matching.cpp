#include <iostream>

using namespace std;

bool isMatch(const char *s, const char *p) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (*p == '\0') {
		return *s == '\0';
	}

	/*�����ǰ�ַ�����һ���ַ��ǡ�*������ô��isMatch(s, p + 2)ΪTRUE��ʾs��p+2��ƥ�䣩
	1."*"ǰ����ַ���S�ǲ�ƥ��ģ���ôֱ��������ǰ�ַ���"*",isMatch(s, p + 2);
	2."*"ǰ����ַ�Ϊ"."������s��ƥ��,��ô�ȼ���ƥ��p�����¸��ַ�����Ϊ��һ���ַ�Ϊ"*"����
		�����ƥ�䣬��ôȡs����һ���ַ����бȽ�"
	*/

	if (*(p + 1) == '*') 
	{
		while (*s != '\0' && (*s == *p || *p == '.'))//ѭ����Ϊ��ƥ�����ظ��ַ�����������߳��Ȳ�ƥ��������s=aaa��p=a*a��
		{
			if (isMatch(s, p + 2)) {
				return true;
			}
			s++;
		}
		return isMatch(s, p + 2);
	}
	else //�����ǰ�ַ�����һ���ַ��ǡ�*������ô��s��pһһ�Ƚ�
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