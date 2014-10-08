#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToInt(string s)
{
	int ret = 0;
	int size = s.size();

	map<char, int> roToInt;
	roToInt.insert(make_pair('I', 1));
	roToInt.insert(make_pair('V', 5));
	roToInt.insert(make_pair('X', 10));
	roToInt.insert(make_pair('L', 50));
	roToInt.insert(make_pair('C', 100));
	roToInt.insert(make_pair('D', 500));
	roToInt.insert(make_pair('M', 1000));

	int pre = 5000;
	int cur = 0;

	for (int i = 0; i < size; i++)
	{
		cur = roToInt[s[i]];
		ret += cur;

		if (cur > pre)
		{
			ret -= 2 * pre;
		}
		pre = cur;
	}
	return ret;
}


int main()
{
	string s = "XC";
	cout << romanToInt(s) << endl;
	//cout << s.substr(0, 1) << endl;
	return 0;
}