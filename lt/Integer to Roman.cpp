#include <iostream>
#include <string>

using namespace std;

const string roman[4][10] = {
	{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
	{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
	{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
	{"", "M", "MM", "MMM", "", "", "", "", "", ""}

};

string intToRoman(int num)
{
	string ret = "";

	int idx = 0;
	while (num)
	{
		ret = roman[idx][num % 10] + ret;//不能为ret += roman[idx][num % 10];因为新的值要放在前面
		num /= 10;
		idx++;
	}
	return ret;
}

int main()
{
	cout << intToRoman(999) << endl;
	return 0;
}