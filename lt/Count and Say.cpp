#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n)
{
	string ret = "1";
	int count = 0;

	for (int i = 2; i <= n; i++)
	{
		char cur = '\0';
		int len = ret.length();
		string nextStr = "";
		count = 0;
		int j = 0;

		while (j < len)
		{
			if (cur == ret[j])
			{
				count++;
			}
			else
			{
				if (cur != '\0')//��ǰ���ֵ��ͬʱ���������ӵ�s��
				{
					nextStr += (char)(count + '0');
					nextStr += cur;
				}

				cur = ret[j];
				count = 1;
			}
			j++;
		}
		/*���һ����ֵͳ�Ƶ�ʱ����Ҫ����*/
		nextStr += (char)(count + '0');
		nextStr += cur;
		
		ret = nextStr;
	}
	
	return ret;
}

int main()
{
	return 0;
}