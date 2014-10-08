#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLastWord(const char *s)
{
	int size = strlen(s);
	int sum = 0;
	bool flag = false;

	if (0 == size)
	{
		return 0;
	}
	
	for (int i = size - 1; i >= 0; i--)
	{
		if (s[i] == '\0' && !flag)
		{
			continue;
		}

		if (s[i] != '\0')
		{
			flag = true;
			sum++;
		}

		if (s[i] == '\0' && flag)
		{
			break;
		}
	}
	return sum;
}