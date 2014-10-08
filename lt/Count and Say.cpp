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
				if (cur != '\0')//与前面的值不同时，进行添加到s中
				{
					nextStr += (char)(count + '0');
					nextStr += cur;
				}

				cur = ret[j];
				count = 1;
			}
			j++;
		}
		/*最后一个数值统计的时候需要加上*/
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